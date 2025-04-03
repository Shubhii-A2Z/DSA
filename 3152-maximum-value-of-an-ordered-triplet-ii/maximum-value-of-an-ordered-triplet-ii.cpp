class Solution {
public:
    typedef long long ll;
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        vector<int> preMax(n);
        vector<int> sufMax(n);
        preMax.front()=nums.front();
        sufMax.back()=nums.back();

        for(int i=1;i<n;++i){
            preMax[i]=max(preMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;--i){
            sufMax[i]=max(sufMax[i+1],nums[i]);
        }

        ll maxVal=0;
        for(int j=1;j<n-1;++j){
            maxVal=max(maxVal,1LL*(preMax[j-1]-nums[j])*sufMax[j+1]);
        }

        return maxVal;
    }
};