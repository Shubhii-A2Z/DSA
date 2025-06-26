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

    int numberOfGoodPaths(vector<int>& val, vector<vector<int>>& edges) {
        if(val.size()==1) return 1;

        int n=val.size();
        DSU dsu(n);

        unordered_map<int,vector<int>> tree;
        for(auto &e:edges){
            int u=e[0], v=e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        map<int,vector<int>> nodeVals; // we'll start from minimum val to max value, hence ordered map
        for(int i=0;i<n;++i){
            nodeVals[val[i]].push_back(i);
        }

        int cnt=n; // since the tree is disconnected, hence every node is good path, starting and ending at itself
        for(auto &[vals,v]:nodeVals){
            for(auto &node:v){ // getting the nodes having similar val
                for(auto &nbr:tree[node]){
                    if(val[nbr]<=vals) dsu.unite(node,nbr);
                }
            }

            unordered_map<int,vector<int>> mp;
            for(auto &node:v){
                mp[dsu.find(node)].push_back(node);
            }

            for(auto &[leader,v]:mp){
                int nodes=v.size();
                cnt+=(nodes*(nodes-1)/2);
            }
        }

        return cnt;
    }
};