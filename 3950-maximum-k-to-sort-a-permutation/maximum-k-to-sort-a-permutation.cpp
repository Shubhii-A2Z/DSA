class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        unordered_map<int,int> mp; //{ele,index}
        for(int i=0;i<nums.size();++i){
            mp[i]=nums[i];
        }

        sort(begin(nums),end(nums));
        int minK=INT_MAX;
        for(int i=0;i<nums.size();++i){
            int currEle=nums[i], actEle=mp[i];
            if(currEle!=actEle){
                minK=min(minK,currEle&actEle);
            }
        }

        return minK==INT_MAX ? 0 : minK;
    }
};