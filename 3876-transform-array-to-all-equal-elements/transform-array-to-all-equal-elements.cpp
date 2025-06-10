class Solution {
public:
    bool canMakeEqual(vector<int>& v, int k) {

        auto f=[&](int val)->int{
            vector<int> nums=v;
            int cnt=0;
            for(int i=0;i+1<nums.size();++i){
                if(nums[i]!=val){
                    nums[i]*=-1; nums[i+1]*=-1;
                    cnt++;
                }
            }
            if(nums.back()!=val) return INT_MAX;
            return cnt;
        };

        int val1=f(1), val2=f(-1);
        return min(val1,val2)<=k ? true : false;
    }
};