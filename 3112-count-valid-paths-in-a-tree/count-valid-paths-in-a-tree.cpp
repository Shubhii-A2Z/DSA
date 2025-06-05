class Solution {
public:
    // used for finding(precomputing) prime numbers in range [1,n]
    // Time:O(nloglog(sqrt(n)))
    // Space:O(n)

    // prime sieve
    // n=10 --> 2 3 5 7
    vector<bool> sieve(int n){

        vector<bool> isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i<=sqrt(n);i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        
        return isPrime;
    }

    

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
                if(rank[xset]>=rank[yset]){
                    parent[yset]=xset;
                    rank[xset]+=rank[yset];
                }
                else{
                    parent[xset]=yset;
                    rank[yset]+=rank[xset];
                }
                return true;
            }
            return false;
        }
    };

    // DSU dsu(n);
    // dsu.unite(edgeList[i][0], edgeList[i][1]); // Connect 2 nodes
    // if(dsu.find(q[0]) == dsu.find(q[1])) // Find will go to the Parent : Same Component - Same Parent

    unordered_map<int,vector<int>> gr;

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> isPrime=sieve(100002);
        DSU dsu(n+1);

        for(auto &e:edges){
            int u=e[0], v=e[1];
            gr[u].push_back(v);
            gr[v].push_back(u);

            if(isPrime[u] || isPrime[v]) continue;
            dsu.unite(u,v); // if both nodes r non-prime, we merge them into a single node
        }

        ll ans=0;
        for(int i=1;i<=n;++i){
            if(!isPrime[i]) continue;  // since we have to start from a prime node we skip the non-prime node
            vector<ll> countNodes;
            ll sum=1;

            for(auto &nbr:gr[i]){
                if(isPrime[nbr]) continue; // prime nodes dont contribute in ans
                countNodes.push_back(dsu.rank[dsu.find(nbr)]);
                sum+=countNodes.back();
            }

            for(auto &i:countNodes){
                sum-=i;
                ans+=(i*sum);
            }
        }

        return ans;
    }
};