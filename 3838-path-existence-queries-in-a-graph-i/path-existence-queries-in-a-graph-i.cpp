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

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        for(int i=0;i<n-1;++i){
            int currE=nums[i];
            int idx=upper_bound(begin(nums),end(nums),currE+maxDiff)-begin(nums);
            idx--;
            if(idx<=i) continue;
            int j=i+1;
            while(j<=idx){
                dsu.unite(i,j);
                j++;
            }
            i=idx-1;
        }

        vector<bool> ans;
        for(auto &q:queries){
            int u=q[0], v=q[1];
            if(dsu.find(u)==dsu.find(v)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};