class Solution {
public:

    // SOS(Sum Of Subsets) DP

    typedef long long ll;
    long long maxProduct(vector<int>& nums) {
        int maxe=*max_element(begin(nums),end(nums));

        int maxBits=log2(maxe)+1;
        int maxMask=(1<<maxBits)-1;

        vector<int> dp(maxMask+1,0); // largest number corresponding to submask of each mask
        for(int ele:nums) dp[ele]=ele;

        for(int i=0;i<maxBits;++i){
            for(int mask=1;mask<=maxMask;++mask){
                if(mask&(1<<i)){
                    dp[mask]=max(dp[mask],dp[mask^(1<<i)]); //taking xor will make that bit unset so that we get a subset of mask
                }
            }
        }

        ll ans=0;
        for(int ele:nums){
            ans=max(ans,1LL*ele*dp[maxMask^ele]); //gives max from subest of mask that donot overlap with ele
        }

        return ans;
    }

};