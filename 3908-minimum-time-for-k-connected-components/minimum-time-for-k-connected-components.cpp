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

    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(!edges.size()) return 0;

        sort(begin(edges),end(edges),[&](auto &a,auto &b){
            return a[2]>b[2];
        });

        auto check=[&](int time)->bool{
            DSU dsu(n);
            for(auto &e:edges){
                int u=e[0], v=e[1], t=e[2];
                if(t>time) dsu.unite(u,v);
                else break;
            }

            unordered_set<int> par;
            for(int i=0;i<n;++i){
                par.insert(dsu.find(i));
            }

            return par.size()>=k;
        };

        ll lo=0, hi=1000000001, ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};