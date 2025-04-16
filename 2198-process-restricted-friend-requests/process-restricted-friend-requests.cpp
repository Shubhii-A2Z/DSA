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
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        DSU dsu(n);
        vector<bool> ans;

        for(auto &rq:req){
            int u=rq[0], v=rq[1];
            int par1=dsu.find(u), par2=dsu.find(v);
            bool yes=true;
            for(auto &ban:res){
                int x=dsu.find(ban[0]), y=dsu.find(ban[1]);
                if((par1==x && par2==y) || (par1==y && par2==x)){
                    yes=false;
                    break;
                }
            }
            if(yes) dsu.unite(u,v);
            ans.push_back(yes);
        }

        return ans;
    }
};