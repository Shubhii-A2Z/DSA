class Solution {
public:
    #define MOD 1000000007
    vector<int> baseUnitConversions(vector<vector<int>>& c) {
        int n=c.size();
        unordered_map<int,vector<pair<int,int>>> gr;
        for(auto &e:c){
            int u=e[0], v=e[1], wt=e[2];
            gr[u].push_back({v,wt});
        }

        unordered_set<int> vis;
        vector<int> factor(n+1);
        factor[0]=1;

        auto dfs=[&](auto &&dfs,int node,int mul)->void{
            factor[node]=mul%MOD;
            vis.insert(node);
            for(auto &[nbr,w]:gr[node]){
                if(vis.count(nbr)) continue;
                dfs(dfs,nbr,(1LL*mul*w)%MOD);
            }
        };

        dfs(dfs,0,1);

        return factor;
    }
};