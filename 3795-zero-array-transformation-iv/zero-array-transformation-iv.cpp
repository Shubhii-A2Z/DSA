class Solution {
public:
    int dp[1001][1001];
    int f(int idx,int target,int k,vector<vector<int>>& q){
        if(target==0) return k;
        if(k>=q.size() || target<0) return INT_MAX;
        int &val=dp[target][k];
        if(val!=-1) return val;
        int ans=f(idx,target,k+1,q);
        if(q[k][0]<=idx && idx<=q[k][1]) ans=min(ans,f(idx,target-q[k][2],k+1,q));
        return val=ans;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1;
        for(int i=0;i<nums.size();++i){
            memset(dp,-1,sizeof(dp));
            ans=max(ans,f(i,nums[i],0,queries));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};