class Solution {
public:
    typedef long long ll;

    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        vector<ll> preSum(n,0);
        for(int i=0;i<n;++i){
            preSum[i]=i>0 ? preSum[i-1]+nums[i] : nums[i];
        }

        int median=n>>1; // finding median idx
        ll val=nums[median]; // finding value at median idx

        // cout<<val<<endl;

        ll leftSum=median>0 ? preSum[median-1] : 0;
        ll rightSum=preSum.back()-preSum[median];

        ll leftToMedian=(median)*val - leftSum;
        ll rightToMedian=rightSum - (n-median-1)*val;

        return leftToMedian+rightToMedian;
    }
};