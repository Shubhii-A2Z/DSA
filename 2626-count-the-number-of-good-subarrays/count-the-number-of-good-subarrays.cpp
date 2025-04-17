class Solution {
public:
    typedef long long ll;
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        ll cnt=0, pairs=0;
        int l=0,r=0;

        while(r<nums.size()){
            mp[nums[r]]++;
            pairs+=(mp[nums[r]]-1);
            while(l<r && pairs>=k){
                cnt+=(nums.size()-r);
                mp[nums[l]]--;
                pairs-=(mp[nums[l]]);
                l++;
            }
            r++;
        }

        return cnt;
    }
};