class Solution {
public:
    // simple take/notTake dp (0/1 knapsack)
    int dp[502][502][27];

    int f(int i,int prevI,int cnt,int k,vector<int> &nums){
        if(cnt>k) return INT_MIN; // invalid subsequence
        if(i>=nums.size()) return 0; // found one valid subsequence

        int &ans=dp[i][prevI+1][cnt]; // +1 is for coordinate shifting since prevI can be '-1' 
        if(ans!=-1) return ans;

        int notTake=f(i+1,prevI,cnt,k,nums);

        int take=0;
        if(prevI==-1 || nums[i]==nums[prevI]) take=1+f(i+1,i,cnt,k,nums);
        else take=1+f(i+1,i,cnt+1,k,nums);

        return ans=max(take,notTake);
    }

    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,0,k,nums);
    }
};