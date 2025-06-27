class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorVal=0;
        for(int e:nums){
            xorVal^=e;
        }
        return xorVal;
    }
};