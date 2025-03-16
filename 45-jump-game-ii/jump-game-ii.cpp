class Solution {
public:
    int dp[10002];
    int f(int idx,vector<int> &nums){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX/2;
        for(int j=1;j<=nums[idx];++j){
            ans=min(ans,1+f(idx+j,nums));
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};