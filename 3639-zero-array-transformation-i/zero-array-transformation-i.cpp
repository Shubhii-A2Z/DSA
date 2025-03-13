class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> q(nums.size(),0);
        for(auto &itr:queries){
            int l=itr[0], r=itr[1];
            q[l]--; 
            (r+1<nums.size()) ? q[r+1]++ : 1;
        }
        for(int i=1;i<nums.size();++i) q[i]+=q[i-1];
        for(int i=0;i<nums.size();++i){
            nums[i]+=q[i];
            if(nums[i]>0) return false;
        }
        return true;
    }
};