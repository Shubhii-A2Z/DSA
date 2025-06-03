class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        unsigned long long tProd=1;
        for(int e:nums) tProd*=(1LL*e);

        for(int mask=0;mask<(1<<nums.size());++mask){
            unsigned long long currProd=1;
            for(int i=0;i<nums.size();++i){
                if(mask&(1<<i)) currProd*=nums[i];
            }
            if(currProd==target && tProd==currProd*target) return true;
        }

        return false;
    }
};