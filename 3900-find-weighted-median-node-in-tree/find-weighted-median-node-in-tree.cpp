class Solution {
public:
    typedef long long ll;
    int maxLog;
    vector<vector<pair<int,ll>>> graph;
    vector<vector<int>> parent;
    vector<int> depth; // depth calculates the "Number of edges" from root to that node
    vector<ll> pathWt; // pathWt calculates the "Sum of edge-Weight" from root to that node
    int N;

    void dfs(int u,int p=-1,int d=0,ll accWt=0){
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

    int lift(int u, int diff){
        while(diff>0){
            int step=log2(diff);
            u=parent[step][u];
            diff-=(1<<step);
        }
        return u;
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

    ll dist(int u,int v){ // finds the "pathSum" bw u and v
        int LCA=lca(u,v);
        return pathWt[u]+pathWt[v]-2*pathWt[LCA];
    }
    
    int edgeCnt(int u,int v) { // "Number of edges" on the simple path between u and v
        int LCA = lca(u,v);
        return depth[u]+depth[v]-2*depth[LCA];
    }


    int findWeightedMedian(int u,int v){
        if(u==v) return u;

        int LCA=lca(u,v);
        int edges_uv=edgeCnt(u,v);
        ll totDist=dist(u,v);

        int lo=0, hi=edges_uv+1, ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            // find the node which is "mid" edges away from u
            int x;
            if(edgeCnt(u,LCA)>=mid){
                x=lift(u,mid); // x is ancestor of u
            }
            else x=lift(v,edges_uv-mid); // x is ancestor of v

            ll d=dist(u,x);
            if(2*d>=totDist){
                ans=x;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }

    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // int n=edges.size()+1; // edges is of length (n-1), where n is number of nodes
        maxLog=32-__builtin_clz(n);

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
            int u=q[0], v=q[1];
            ans.push_back(findWeightedMedian(u,v));
        }

        return ans;
    }
};