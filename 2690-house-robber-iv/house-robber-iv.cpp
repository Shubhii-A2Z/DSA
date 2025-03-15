class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto check=[&](int mid)->bool{
            int i=0, cnt=0;
            while(i<nums.size()){
                if(nums[i]<=mid){
                    cnt++;
                    i+=2;
                }
                else i++;
            }
            return cnt>=k;
        };

        int lo=1, hi=*max_element(begin(nums),end(nums)), ans=1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};