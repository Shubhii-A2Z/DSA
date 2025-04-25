class Solution {
public:
    typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n=nums.size();

        vector<ll> v(n,0);

        unordered_map<ll,ll> mp;
        mp[0]=1;
        ll cnt=0;

        for(int i=0;i<n;++i){
            v[i]=i>0 ? v[i-1]+(nums[i]%mod==k) : (nums[i]%mod==k);
            cnt+=(mp[(v[i]+mod-k)%mod]);
            mp[v[i]%mod]++;
        }

        return cnt;
    }
};