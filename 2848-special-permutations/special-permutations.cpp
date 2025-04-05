class Solution {
public:
    #define MOD 1000000007
    int dp[16][(1<<16)];

    int f(int prevId,int mask,vector<int> &nums){
        if(mask==((1<<nums.size())-1)) return 1;

        int &ans=dp[prevId+1][mask];
        if(ans!=-1) return ans;

        int cnt=0;
        for(int j=0;j<nums.size();++j){
            if(mask&(1<<j)) continue;
            if(prevId==-1) cnt=(cnt+f(j,mask|(1<<j),nums))%MOD;
            else if(nums[prevId]%nums[j]==0 || nums[j]%nums[prevId]==0) cnt=(cnt+f(j,mask|(1<<j),nums))%MOD;
        }
        return ans=cnt%MOD;
    }

    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(-1,0,nums);
    }
};