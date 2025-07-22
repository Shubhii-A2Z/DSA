class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        // exactly same qn as find longest subarray with unique elements

        unordered_map<int,int> mp;
        int l=0,r=0;
        int maxSum=0, currSum=0;

        while(r<nums.size()){
            mp[nums[r]]++;
            currSum+=nums[r];
            while(mp.size()<r-l+1){
                mp[nums[l]]--;
                if(!mp[nums[l]]) mp.erase(nums[l]);
                currSum-=nums[l];
                l++;
            }
            maxSum=max(maxSum,currSum);
            r++;
        }

        maxSum=max(maxSum,currSum); // for the last subarray 

        return maxSum;
    }
};