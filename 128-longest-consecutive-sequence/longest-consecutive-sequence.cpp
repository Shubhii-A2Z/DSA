class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        int mine=*min_element(begin(nums),end(nums));
        // int maxe=*max_element(begin(nums),end(nums));

        set<int> s(begin(nums),end(nums));

        int maxLen=0, prevE=mine-1;
        int currLen=0;
        for(auto &e:s){
            cout<<prevE<<' '<<e<<endl;
            if(e==prevE+1){
                currLen++;
            }
            else{
                maxLen=max(maxLen,currLen);
                currLen=1;
            }
            prevE=e;
        }

        maxLen=max(maxLen,currLen);

        return maxLen;
    }
};