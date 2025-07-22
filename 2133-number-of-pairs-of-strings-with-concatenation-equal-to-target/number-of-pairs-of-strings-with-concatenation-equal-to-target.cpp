class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                string s1=nums[i], s2=nums[j];
                if(s1+s2==target) cnt++;
                if(s2+s1==target) cnt++;
            }
        }
        return cnt;
    }
};