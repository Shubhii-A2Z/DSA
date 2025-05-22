class Solution {
public:
    int maxLog=25;
    vector<vector<pair<int,int>>> graph;
    vector<vector<int>> parent;
    vector<int> depth; // depth calculates the "edges" from root to that node
    vector<int> pathWt; // pathWt calculates the "sum of edges" from root to that node
    int N;

    void dfs(int u,int p=-1,int d=0,int accWt=0){
        depth[u]=d;
        pathWt[u]=accWt;
        parent[0][u]=p;

        for(auto v:graph[u]){
            if(v.first==p) continue;
            dfs(v.first,u,d+1,accWt+v.second);
        }
    }

    void build(){
        for(int i=0;i<N;i++){
            depth[i]=-1;
        }
        dfs(0);
        for(int i=1;i<maxLog;i++){
            for(int u=0;u<N;u++){
                if(parent[i-1][u]!=-1){
                    parent[i][u]=parent[i-1][parent[i-1][u]];
                }
            }
        }
    }

    int lca(int u,int v){
        if(depth[u]>depth[v]) swap(u,v);
        int diff=depth[v]-depth[u];
        
        for(int i=maxLog-1;i>=0;i--){
            if(diff&(1<<i)){
                v=parent[i][v];
            }
        }
        if(u==v) return v;

        for(int i=maxLog-1;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u=parent[i][u];
                v=parent[i][v];
            }
        }

        return parent[0][v];
    }
    
    int dist(int u,int v){
        int LCA=lca(u,v);
        return pathWt[u]+pathWt[v]-2*pathWt[LCA];
    }

    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        N=n;
        graph.resize(n);
        depth.resize(n);
        pathWt.resize(n);
        parent.resize(maxLog,vector<int>(n,-1));

        for(auto &e:edges){
            int u=e[0], v=e[1], w=e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        build();

        vector<int> ans;

        for(auto &q:queries){
            int src1=q[0], src2=q[1], dest=q[2];
            int LCA=lca(src1,src2);
            int minDist=(dist(src1,dest)+dist(src2,dest)+dist(src1,src2))/2;
            ans.push_back(minDist);
        }

        return ans;
    }
};