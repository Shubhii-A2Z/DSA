class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll len=0, cnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]){
                cnt+=(len*(len+1)/2);
                len=0;
            }
            else len++;
        }
        cnt+=(len*(len+1)/2);
        return cnt;
    }
};