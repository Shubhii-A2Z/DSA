class Solution {
public:
    vector<int> future,present;
    unordered_map<int,vector<int>> gr;
    vector<vector<vector<int>>> dp;

    vector<int> f(int node,bool discount,int budget){
        if(dp[node][discount].size()){
            return dp[node][discount];
        }

        vector<int> profitDp(budget+1,0);

        //option1:Don't buy current stocks
        vector<int> option1(budget+1,0);
        for(auto &ch:gr[node]){
            vector<int> childProfit=f(ch,0,budget);
            vector<int> temp(budget+1,0);
            for(int i=0;i<=budget;++i){
                for(int budAllocated=0;budAllocated<=i;++budAllocated){
                    temp[i]=max(temp[i],option1[budAllocated]+childProfit[i-budAllocated]);
                }
            }
            option1=temp;
        }

        //option2:Buy the current stocks
        int cost=discount ? present[node]/2 : present[node];
        int currProfit=future[node]-cost;
        vector<int> option2Updated(budget+1,0);
        if(cost<=budget){
            vector<int> option2(budget+1,0);
            for(auto &ch:gr[node]){
                vector<int> childProfit=f(ch,1,budget);
                vector<int> temp(budget+1,0);
                for(int i=0;i<=budget;++i){
                    for(int budAllocated=0;budAllocated<=i;++budAllocated){
                        temp[i]=max(temp[i],option2[budAllocated]+childProfit[i-budAllocated]);
                    }
                }
                option2=temp;
            }

            for(int i=cost;i<=budget;++i){
                option2Updated[i]=currProfit+option2[i-cost];
            }
        } 

        for(int i=0;i<=budget;++i){ // choosing best option among both
            profitDp[i]=max(option1[i],option2Updated[i]);
        }

        return dp[node][discount]=profitDp;
    }

    int maxProfit(int n, vector<int>& p, vector<int>& ft, vector<vector<int>>& hierarchy, int budget) {
        present=p;
        future=ft;
        for(auto &h:hierarchy){
            int u=h[0]-1, v=h[1]-1;
            gr[u].push_back(v);
        }

        dp.resize(n,vector<vector<int>>(2));
        vector<int> profit=f(0,0,budget);

        return *max_element(begin(profit),end(profit));
    }
};