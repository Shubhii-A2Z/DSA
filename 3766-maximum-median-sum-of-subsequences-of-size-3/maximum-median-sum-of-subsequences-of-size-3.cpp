class Solution {
public:
    typedef long long ll;
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        ll tSum=0;
        int i=0, j=nums.size()-2;
        while(i<j){
            tSum+=(nums[j]);
            i++;
            j-=2;
        }
        return tSum;
    }
};