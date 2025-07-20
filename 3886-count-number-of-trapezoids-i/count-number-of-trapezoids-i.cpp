class Solution {
public:
    #define MOD 1000000007

    typedef long long ll;

    ll expo(ll a,ll b, ll m=MOD){ if(b==0) return 1%m; if(b%2==0){ int t=expo(a,b/2); return (1LL*t*t%m); }else{ int t=expo(a,(b-1)/2); t=(1LL*t*t)%m; return (1LL*a*t)%m; } }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp; // {y-axis,numberofPoints}
        for(auto &e:points){
            int x=e[0], y=e[1];
            mp[y]++;
        }

        ll val1=0,val2=0;
        for(auto &[y,num]:mp){
            if(num<2) continue;
            ll e=(1LL*num*(num-1)/2);
            val1+=e;
            val2+=(e*e);
        }

        ll ans=val1*val1-val2;
        ans/=2;
        ans%=MOD;

        return ans;

    }
};