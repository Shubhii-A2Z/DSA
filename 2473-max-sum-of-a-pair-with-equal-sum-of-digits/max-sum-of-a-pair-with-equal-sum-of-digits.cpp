class Solution {
public:
    typedef long long ll;
    int maximumSum(vector<int>& nums) {
        unordered_map<int,multiset<ll>> mp;
        auto findSum=[&](int num){
            ll sum=0;
            int x=num;
            while(num){
                sum+=(num%10);
                num/=10;
            }
            mp[sum].insert(x);
        };  

        for(auto &ele:nums) findSum(ele);

        int ans=-1;
        for(auto &itr:mp){
            if(itr.second.size()>=2){
                auto s=itr.second.rbegin();
                int maxe=*s;
                s++;
                int maxe2=*s;
                ans=max(ans,maxe+maxe2);
            }
        }

        return ans;
    }
};