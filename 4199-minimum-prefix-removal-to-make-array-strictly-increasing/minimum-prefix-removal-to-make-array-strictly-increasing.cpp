class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        auto f=[&](int len)->bool{
            for(int i=len+1;i<nums.size();++i){
                if(nums[i]<=nums[i-1]) return false;
            }
            return true;
        };

        int lo=0, hi=nums.size(), ans=-1;
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