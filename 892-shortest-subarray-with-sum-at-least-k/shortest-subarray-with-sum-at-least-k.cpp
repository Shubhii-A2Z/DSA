class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> pr;

    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> preSum(n);

        for(int i=0;i<n;++i){
            preSum[i]=i>0 ? nums[i]+preSum[i-1] : nums[i];
        }

        deque<pr> dq;
        int minLen=INT_MAX;

        for(int i=0;i<n;++i){
            if(preSum[i]>=k) minLen=min(minLen,i+1);

            while(dq.size() && preSum[i]-dq.back().first>=k){
                minLen=min(minLen,i-dq.back().second);
                dq.pop_back(); // removing since its no longer needed, it will only increase the length of subarray
            }

            while(dq.size() && dq.front().first>=preSum[i]) dq.pop_front();

            dq.push_front({preSum[i],i});
        }

        return minLen==INT_MAX ? -1 : minLen;
    }
};