class Solution {
public:
    typedef long long ll;
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        ll mine=0, maxe=0;
        ll currEle=0;

        for(int i=0;i<diff.size();++i){
            currEle+=(diff[i]);
            mine=min(mine,currEle);
            maxe=max(maxe,currEle);
        }

        ll lowerDiff=lower-mine, upperDiff=upper-maxe;

        int ans=upperDiff-lowerDiff+1;
        return ans>=0 ? ans : 0;
    }
};