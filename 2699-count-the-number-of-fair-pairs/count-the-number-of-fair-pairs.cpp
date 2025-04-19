class Solution {
public:
    #define all(v) v.begin(),v.end()
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            int sumlower=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums)-1;
            int sumupper=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums)-1;
            cnt+=(sumupper-sumlower);
        }
        return cnt;
    }
};