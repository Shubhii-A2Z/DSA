class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int maxe=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    count[i]=count[prev];
                }
                else if(nums[prev]<nums[i] && dp[prev]+1==dp[i]){
                    count[i]+=count[prev];
                }
            }
            maxe=max(maxe,dp[i]);
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxe) nos+=count[i];
        }
        return nos;
    }
};