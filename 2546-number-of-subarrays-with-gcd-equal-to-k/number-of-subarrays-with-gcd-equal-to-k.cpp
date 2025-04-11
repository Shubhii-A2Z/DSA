class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            int currGcd=nums[i];
            for(int j=i;j<nums.size();++j){
                currGcd=__gcd(currGcd,nums[j]);
                if(currGcd==k) cnt++;
                if(currGcd<k) break;
            }
        }

        return cnt;
    }
};