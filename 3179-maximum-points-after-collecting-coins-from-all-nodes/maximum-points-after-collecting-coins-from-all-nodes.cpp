class Solution {
public:
    typedef long long ll;
    unordered_map<int,vector<int>> gr;
    vector<int> coins;
    int K;
    int dp[100005][15];

    int f(int node,int by_2,int par){
        if(by_2>14) return 0;

        int &ans=dp[node][by_2];
        if(ans!=-1) return ans;
        
        int val=coins[node];
        val/=(1<<by_2);

        ll with_by_2=val/2;
        for(auto &child:gr[node]){
            if(child==par) continue;
            with_by_2+=f(child,by_2+1,node);
        }

        ll with_minus_k=val-K;
        for(auto &child:gr[node]){
            if(child==par) continue;
            with_minus_k+=f(child,by_2,node);
        }

        return ans=max(with_by_2,with_minus_k);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& c, int k) {
        coins=c;
        K=k;
        for(auto &e:edges){
            int u=e[0], v=e[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        memset(dp,-1,sizeof(dp));
        return f(0,0,-1);
    }
};