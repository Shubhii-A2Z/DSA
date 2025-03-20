class Solution {
public:
    

// Path Compression + Union By Rank

typedef long long ll;

class DSU {
public:
    vector<ll> parent, rank, andVal;
    DSU(ll n){
        parent.resize(n, 0);
        rank.resize(n, 1);
        andVal.resize(n,INT_MAX);
        for(ll i=0;i<n;i++) parent[i] = i;
    }
    
    ll find(ll x){ // O(log*N) , max O(5)
        return parent[x] = parent[x] == x ? x : find(parent[x]);
    }
    
    void reset(ll node){
        parent[node]=node;
    }

    int andValue(ll node){
        return andVal[find(node)];
    }

    bool unite(ll x, ll y,ll edge){ // O(1)
        ll xset = find(x), yset = find(y);
        if(xset != yset){
            if(rank[xset] < rank[yset]){
                parent[xset] = yset;
                andVal[yset]&=(andVal[xset]&edge);
                cout<<andVal[yset]<<endl;
            }
            else{
                parent[yset] = xset;
                andVal[xset]&=(andVal[yset]&edge);
                cout<<andVal[xset]<<endl;
            }
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        else{
            andVal[xset]&=edge;
        }
        return false;
    }
};

// DSU dsu(n);
// dsu.unite(edgeList[i][0], edgeList[i][1]); // Connect 2 nodes
// if(dsu.find(q[0]) == dsu.find(q[1])) // Find will go to the Parent : Same Component - Same Parent

// "find" is not a reserved keyword but a function name in STL, so you can use it for your own variables or functions
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto &e:edges){
            int u=e[0], v=e[1], wt=e[2];
            // cout<<u<<" "<<v<<" "<<wt<<endl;
            dsu.unite(u,v,wt);
        }

        vector<int> ans;
        for(auto &q:query){
            int u=q[0], v=q[1];
            if(dsu.find(u)!=dsu.find(v)) ans.push_back(-1);
            else{
                ans.push_back(dsu.andValue(u));
            }
        }

        return ans;
    }
};