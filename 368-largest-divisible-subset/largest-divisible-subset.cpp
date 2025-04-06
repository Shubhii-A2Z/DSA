class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),prev_idx(n);
        int max_len=1;
        int last_idx=0;
        for(int i=0;i<n;i++){
            prev_idx[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    prev_idx[i]=prev;
                }
            }
            if(dp[i]>max_len){
                max_len=dp[i];
                last_idx=i;
            }
        }
        vector<int> lds;
        lds.push_back(nums[last_idx]);
        while(prev_idx[last_idx]!=last_idx){
            last_idx=prev_idx[last_idx]; //backtracking to idx of prev element of largest lds
            lds.push_back(nums[last_idx]);
        }
        reverse(lds.begin(),lds.end());
        return lds;
    }
};