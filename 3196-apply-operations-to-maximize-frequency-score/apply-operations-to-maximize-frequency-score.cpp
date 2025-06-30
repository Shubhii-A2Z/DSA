class Solution {
public:
    typedef long long ll;
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        vector<ll> preSum(n,0);
        for(int i=0;i<n;++i){
            preSum[i]=i>0 ? preSum[i-1]+nums[i] : nums[i];
        }

        auto isPossible=[&](int sze)->bool{
            int l=0, r=sze-1;

            while(r<nums.size()){
                int median=(l+r)>>1; // finding middle idx
                ll val=nums[median]; // value present at middle index
                
                ll leftSum=(median>0 ? preSum[median-1] : 0) - (l>0 ? preSum[l-1]: 0); // sum of elements at left of subarray
                ll leftToMedian=(median-l+1)*val-leftSum; // ops to convert elements at left to median

                ll rightSum=preSum[r]-preSum[median]; // sum of elements at right of subarray
                ll rightToMedian=rightSum-(r-median+1)*val;;  // ops to convert elements at right to median

                if((leftToMedian+rightToMedian)<=k) return true;
                l++;
                r++;
            }

            return false;
        };

        int lo=1, hi=nums.size(), ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(isPossible(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
    }
};