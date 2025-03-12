class Solution {
public:
    typedef long long ll;
    long long repairCars(vector<int>& ranks, int cars) {
        auto check=[&](ll mid)->bool{
            ll c=cars;
            for(int i=0;i<ranks.size();++i){
                ll maxPossible=sqrtl(mid/ranks[i]);
                c-=maxPossible;
            }
            return c<=0;
        };

        ll lo=1,hi=1e18, ans=-1;
        while(lo<=hi){
            ll mid=(lo+hi)>>1;
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};