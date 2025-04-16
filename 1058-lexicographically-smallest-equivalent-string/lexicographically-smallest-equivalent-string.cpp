class Solution {
public:
    // Path Compression + Union By Rank

    typedef long long ll;

    class DSU {
    public:
        vector<ll> parent;
        DSU(ll n){
            parent.resize(n, 0);
            for(ll i=0;i<n;i++) parent[i] = i;
        }
        
        ll find(ll x){ // O(log*N) , max O(5)
            return parent[x] = parent[x] == x ? x : find(parent[x]);
        }
        
        void reset(char node){
            parent[node-'a']=node-'a';
        }

        bool unite(char x, char y){ // O(1)
            ll xset = find(x-'a'), yset = find(y-'a');
            if(xset != yset){
                if(xset < yset) parent[yset]=xset;
                else parent[xset]=yset;
                return true;
            }
            return false;
        }
    };

    // DSU dsu(n);
    // dsu.unite(edgeList[i][0], edgeList[i][1]); // Connect 2 nodes
    // if(dsu.find(q[0]) == dsu.find(q[1])) // Find will go to the Parent : Same Component - Same Parent

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0;i<s1.length();++i){
            dsu.unite(s1[i],s2[i]);
        }

        for(int i=0;i<baseStr.length();++i){
            baseStr[i]=dsu.find(baseStr[i]-'a')+'a';
        }

        return baseStr;
    }
};