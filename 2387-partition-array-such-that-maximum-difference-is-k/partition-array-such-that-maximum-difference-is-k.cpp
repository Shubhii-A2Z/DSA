class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int cnt=0;
        int mine=nums.front();

        for(int i=1;i<nums.size();++i){
            if(nums[i]-mine>k){
                cnt++;
                mine=nums[i];
            }
        }

        return cnt+1;
    }
};