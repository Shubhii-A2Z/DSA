class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr_len=0;
        int max_len=0;
        int max_ele=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_ele){
                max_ele=nums[i];
                curr_len=1;
                max_len = 1; // Reset max_len when a new max element is found
            }
            else if(nums[i]==max_ele){
                curr_len++;
            }
            else{ // Reset curr_len to 0 when encountering a smaller element
                curr_len=0;
            }
            max_len=max(max_len,curr_len);
        }
        return max_len;
    }
};