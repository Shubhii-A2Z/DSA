class Solution {
public:
    typedef long long ll;
    ll dp[255][255];
    // standard "partition dp" technique

    int f(int i,int cuts,int k,vector<int> &nums){
        if(i>=nums.size()) return INT_MAX;
        if(cuts==k-1){ // for k subarrays, atmost k-1 cuts r possible
            int currXor=0;
            for(int j=i;j<nums.size();++j) currXor^=nums[j]; // finding xor val of the last subarray
            return dp[i][cuts]=currXor;
        }

        if(dp[i][cuts]!=-1) return dp[i][cuts];

        int currXor=0, minXor=INT_MAX;
        for(int j=i;j<nums.size();++j){ // trying out all partitions possible
            currXor^=nums[j];
            int val=f(j+1,cuts+1,k,nums);
            int maxP=max(val,currXor); // maximum XOR among these k subarrays.
            minXor=min(minXor,maxP); // minimum possible value of the maximum XOR
        }
        
        return dp[i][cuts]=minXor;
    }

    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,k,nums);
    }
};