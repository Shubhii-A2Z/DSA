class Solution {
public:
    unordered_map<int,vector<int>> gr;
    vector<int> ans, count;

    void dfs_in(int node,int par){
        for(auto &child:gr[node]){
            if(child==par) continue;
            dfs_in(child,node);
            count[node]+=count[child];
            ans[node]+=(ans[child]+count[child]);
        }
    }

    void dfs_out(int node,int par,int n){
        for(auto &child:gr[node]){
            if(child==par) continue;
            int val=ans[node]-ans[child]-count[child]; // removing contribution from current root node
            ans[child]+=val+(n-count[child]); // adding contribution of 'node', since the 'child' is now the root node
            dfs_out(child,node,n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans=vector<int>(n,0);
        count=vector<int>(n,1);

        for(auto &e:edges){
            int u=e[0], v=e[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        dfs_in(0,-1);
        dfs_out(0,-1,n);

        return ans;
    }
};