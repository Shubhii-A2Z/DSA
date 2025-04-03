class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> preMin(n), sufMin(n);
        preMin.front()=nums.front();
        sufMin.back()=nums.back();

        for(int i=1;i<n;++i){
            preMin[i]=min(preMin[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;--i){
            sufMin[i]=min(sufMin[i+1],nums[i]);
        }

        int mine=INT_MAX;
        for(int j=1;j+1<n;++j){
            int currEle=nums[j], leftEle=preMin[j-1], rightEle=sufMin[j+1];
            if(currEle<=leftEle || currEle<=rightEle) continue;
            mine=min(mine,currEle+leftEle+rightEle);
        }

        return mine==INT_MAX ? -1 : mine;
    }
};