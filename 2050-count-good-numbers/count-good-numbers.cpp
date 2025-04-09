class Solution {
public:
    typedef long long ll;
    #define MOD 1000000007

    ll expo(ll a,ll b, ll m=MOD){ if(b==0) return 1%m; if(b%2==0){ int t=expo(a,b/2); return (1LL*t*t%m); }else{ int t=expo(a,(b-1)/2); t=(1LL*t*t)%m; return (1LL*a*t)%m; } }

    ll ceil(ll a,ll b){
        return (a+b-1)/b;
    }

    int countGoodNumbers(long long n) {
        ll evenPos=ceil(n,2), oddPos=n/2;
        ll ans=(expo(5,evenPos)%MOD*expo(4,oddPos)%MOD)%MOD;
        return int(ans);
    }
};