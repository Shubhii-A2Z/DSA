class Solution {
public:
    int minOperations(vector<int>& nums) {
        multiset<int> s(begin(nums),end(nums));
        set<int> s1(begin(nums),end(nums));

        int i=0, c=0;
        while(i<nums.size() && s1.size()!=nums.size()-i){
            s.erase(s.find(nums[i]));
            if(s.find(nums[i])==s.end()) s1.erase(nums[i]); 
            if(i+1<nums.size()){
                s.erase(s.find(nums[i+1]));
                if(s.find(nums[i+1])==s.end()) s1.erase(nums[i+1]);
            }
            if(i+2<nums.size()){
                s.erase(s.find(nums[i+2]));
                if(s.find(nums[i+2])==s.end()) s1.erase(nums[i+2]);
            }
            i+=3;
            c++;
        }

        return c;
    }
};