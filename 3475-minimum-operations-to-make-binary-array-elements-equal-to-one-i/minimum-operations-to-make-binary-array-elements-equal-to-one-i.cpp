class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k=3;
        int ans=0,flips=0;
        vector<bool> isFlipped(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                flips-=isFlipped[i-k];
            }
            if((nums[i]==0 && !(flips&1)) || (nums[i]==1 && (flips&1))){
                if(i+k>nums.size()) return -1;
                ans++;
                flips++;
                isFlipped[i]=true;
            }
        }
        return ans;
    }
};