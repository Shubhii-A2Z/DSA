class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,vector<int>> graph;
        vector<int> parent(edges.size()+1),depth(edges.size()+1);

        for(auto &itr:edges){
            graph[itr[0]].push_back(itr[1]);
            graph[itr[1]].push_back(itr[0]);
        }

        auto dfs=[&](auto &&dfs,int node,int par,int d)->void{
            depth[node]=d;
            parent[node]=par;
            for(auto &nbr:graph[node]){
                if(nbr!=par)
                    dfs(dfs,nbr,node,d+1);
            }
        };

        auto dfs2=[&](auto &&dfs2,int node,int par,vector<int> &amount)->int{
            int total=amount[node], maxProfit=INT_MIN;
            for(auto &nbr:graph[node]){
                if(nbr!=par)
                    maxProfit=max(maxProfit,dfs2(dfs2,nbr,node,amount));
            }
            return maxProfit==INT_MIN ? total : total+maxProfit;
        };

        dfs(dfs,0,-1,0);

        int curr=bob, bobDepth=0;
        while(curr!=-1){ //backtracking the path of bob using parent and depth vector
            if(depth[curr]>bobDepth){
                amount[curr]=0;
            }
            else if(depth[curr]==bobDepth){
                amount[curr]/=2;
            }
            curr=parent[curr];
            bobDepth++;
        }

        return dfs2(dfs2,0,-1,amount);
    }
};