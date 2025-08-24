class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int len=0;
        int k=1;
        int flips=0;
        int max_len=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                } 
                else{
                    len=j-i;
                    max_len=max(max_len,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len=j-i;
        max_len=max(max_len,len);
        return max_len-1;
    }
};