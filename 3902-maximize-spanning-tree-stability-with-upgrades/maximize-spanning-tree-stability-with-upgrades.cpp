class Solution {
public:
    // Path Compression + Union By Rank
    typedef long long ll;

    class DSU {
    public:
        vector<ll> parent, rank;
        DSU(ll n){
            parent.resize(n, 0);
            rank.resize(n, 1);
            
            for(ll i=0;i<n;i++) parent[i] = i;
        }
        
        ll find(ll x){ // O(log*N) , max O(5)
            return parent[x] = parent[x] == x ? x : find(parent[x]);
        }
        
        void reset(ll node){
            parent[node]=node;
        }

        bool unite(ll x, ll y){ // O(1)
            ll xset = find(x), yset = find(y);
            if(xset != yset){
                rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
                rank[xset] += rank[xset] == rank[yset];
                return true;
            }
            return false;
        }
    };

    // DSU dsu(n);
    // dsu.unite(edgeList[i][0], edgeList[i][1]); // Connect 2 nodes
    // if(dsu.find(q[0]) == dsu.find(q[1])) // Find will go to the Parent : Same Component - Same Parent

    struct state{
        int a,b,c; // {u,v,s}
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);

        for(auto &e:edges){
            int u=e[0], v=e[1], st=e[2], must=e[3];
            if(must==1){ // this edge must be included
                if(!dsu.unite(u,v)) return -1; // cycle is formed, hence no spanning tree possible
                dsu.unite(u,v); 
            }
        }

        auto canBuild=[&](int stability)->bool{
            DSU dsu2=dsu; // including all must edges by default
            vector<state> optionalEdge;

            for(auto &e:edges){
                int u=e[0], v=e[1], st=e[2], must=e[3];
                if(must==1){
                    if(st<stability) return false; // can't be upgraded, hence spanning tree not possible
                }
                else{
                    if(st>=stability){ // no upgrade needed
                        dsu2.unite(u,v);
                    }
                    else{ //upgrade needed
                        if(2*st>=stability){
                            optionalEdge.push_back({u,v,st});
                        }
                    }
                }
            }

            int ops=0;
            for(auto &[u,v,st]:optionalEdge){ // selecting only those nodes which r not in same component, to create a spanning tree
                if(dsu2.find(u)!=dsu2.find(v)){
                    dsu2.unite(u,v);
                    ops++;
                    if(ops>k) return false;
                }
            }

            unordered_set<int> par;
            for(int i=0;i<n;++i){
                par.insert(dsu2.find(i));
            }

            return par.size()==1; // checking if all nodes r in single component i.e. have a single parent
        };  

        int lo=1, hi=2*100002, ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(canBuild(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
    }
};