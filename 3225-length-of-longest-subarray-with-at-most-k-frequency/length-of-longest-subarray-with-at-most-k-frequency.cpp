class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0,r=0;

        int maxLen=1;
        while(r<nums.size()){
            int ele=nums[r];
            mp[ele]++;
            while(l<nums.size() && mp[ele]>k){
                mp[nums[l]]--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};