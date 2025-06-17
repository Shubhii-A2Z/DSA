class Solution {
public:
    #define MOD 1000000007
    typedef long long ll;
    vector<ll> fact;
    vector<ll> invFact;

    ll expo(ll a,ll b, ll m=MOD){ 
        if(b==0) return 1%m; 
        if(b%2==0){ 
            int t=expo(a,b/2); 
            return (1LL*t*t%m); 
        }
        else{ 
            int t=expo(a,(b-1)/2); 
            t=(1LL*t*t)%m; 
            return (1LL*a*t)%m; 
        } 
    }

    void precomputefactorials(ll n){
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%MOD; // O(n)
        invFact[n]=expo(fact[n],MOD-2);
        for(int i=n-1;i>=0;i--) invFact[i]=(invFact[i+1]*(i+1))%MOD; // O(n)
    }

    ll nCr(ll n,ll r){
        if(r<0 || r>n) return 0;
        return ((fact[n]*invFact[r])%MOD*invFact[n-r])%MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputefactorials(n);

        int buckets=n-k;
        int dividers=nCr(n-1,buckets-1);

        ll ans=expo(m-1,buckets-1)%MOD;
        ans=(ans*m)%MOD;
        ans=(ans*dividers)%MOD;
        return int(ans);
    }
};