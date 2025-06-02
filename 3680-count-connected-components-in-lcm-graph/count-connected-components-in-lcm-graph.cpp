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

    int countComponents(vector<int>& nums, int threshold) {
        sort(begin(nums),end(nums));

        int cc=0;
        while(nums.size() && nums.back()>threshold){
            cc++;
            nums.pop_back();
        }

        if(!nums.size()) return cc;

        DSU dsu(threshold+1);
        for(int e:nums){
            for(int i=e;i<=threshold;i+=e){
                dsu.unite(e,i);
            }
        }

        unordered_set<int> uniqueParents;
        for(auto &e:nums){
            uniqueParents.insert(dsu.find(e));
        }

        return uniqueParents.size()+cc;
    }
};