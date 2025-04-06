class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> preMin(n,0), sufMax(n,0);

        for(int i=0;i<n;++i){
            preMin[i]=i>0 ? min(preMin[i-1],nums[i]) : nums[i];
        }

        for(int i=n-1;i>=0;--i){
            sufMax[i]=i+1<n ? max(sufMax[i+1],nums[i]) : nums[i];
        }

        for(int j=1;j<n-1;++j){
            int minleft=preMin[j-1], maxRight=sufMax[j+1];
            if(minleft<nums[j] && nums[j]<maxRight) return true;
        }
        return false;
    }
};