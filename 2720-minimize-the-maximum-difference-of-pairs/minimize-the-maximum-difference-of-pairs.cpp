class Solution {
public:

    // amazing "binary search" qn asked by "META"

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        auto f=[&](int diff)->bool{
            int cnt=0, i=0;
            while(i<n-1){
                if(nums[i+1]-nums[i]<=diff){
                    cnt++;
                    i+=2;
                }
                else i++;
            }
            return cnt>=p;
        };

        int lo=0, hi=nums.back()-nums.front(), ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }

};