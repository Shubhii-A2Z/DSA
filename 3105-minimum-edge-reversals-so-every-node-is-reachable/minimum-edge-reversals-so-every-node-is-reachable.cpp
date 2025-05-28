class Solution {
public:
    unordered_map<int,vector<int>> out_edge, in_edge;
    vector<int> down,up;

    void dfs_in(int node,int par){
        for(auto &child:out_edge[node]){
            if(child==par) continue;
            dfs_in(child,node);
            down[node]+=down[child];
        }
        for(auto &child:in_edge[node]){
            if(child==par) continue;
            dfs_in(child,node);
            down[node]+=(1+down[child]);
        }
    }

    void dfs_out(int node,int par){
        for(auto &child:out_edge[node]){
            if(child==par) continue;
            up[child]=1+up[node]+down[node]-down[child];
            dfs_out(child,node);
        }
        for(auto &child:in_edge[node]){
            if(child==par) continue;
            up[child]=up[node]+down[node]-down[child]-1;
            dfs_out(child,node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        down.resize(n,0); up.resize(n,0);
        for(auto &e:edges){
            int u=e[0], v=e[1];
            out_edge[u].push_back(v);
            in_edge[v].push_back(u);
        }

        dfs_in(0,-1);
        dfs_out(0,-1);

        vector<int> ans(n);
        for(int i=0;i<n;++i){
            ans[i]=down[i]+up[i];
        }

        return ans;
    }
};