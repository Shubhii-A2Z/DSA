class Solution {
public:
    unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> dp;
    int f(int i,int currSum,int prod,int type,int k,int limit,vector<int> &nums){
        if(i>=nums.size()){
            return currSum==k && type!=0 && prod<=limit ? prod : -1;
        }

        if(dp.count(i) && dp[i].count(currSum) && dp[i][currSum].count(prod) && dp[i][currSum][prod].count(type)){
            return dp[i][currSum][prod][type];
        }

        int ans=f(i+1,currSum,prod,type,k,limit,nums);

        if(type==0){ // no element chosen so far
            ans=max(ans,f(i+1,currSum+nums[i],prod*nums[i],1,k,limit,nums));
        }
        else if(type==1){ // odd position 
            ans=max(ans,f(i+1,currSum-nums[i],min(prod*nums[i],limit+1),2,k,limit,nums));
        }
        else if(type==2){ // even position 
            ans=max(ans,f(i+1,currSum+nums[i],min(prod*nums[i],limit+1),1,k,limit,nums));
        }

        return dp[i][currSum][prod][type]=ans;
    }

    int maxProduct(vector<int>& nums, int k, int limit) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(k>sum || k<-sum) return -1;
        dp.clear();
        return f(0,0,1,0,k,limit,nums);
    }
};