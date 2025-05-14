class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int max_diff=INT_MIN;
        for(int i=1;i<nums.size();i++){
            max_diff=max(max_diff,nums[i]-nums[i-1]);
        }
        return max_diff;
    }
};