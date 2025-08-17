class Solution {
public:
    #define MOD 1000000007
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &q:queries){
            int l=q[0], r=q[1], k=q[2], v=q[3];
            for(int idx=l;idx<=r;idx+=k){
                nums[idx]=(1LL*nums[idx]*v)%MOD;
            }
        }
        
        int Xor=0;
        for(auto &e:nums) Xor^=e;
        return Xor;
    }
};