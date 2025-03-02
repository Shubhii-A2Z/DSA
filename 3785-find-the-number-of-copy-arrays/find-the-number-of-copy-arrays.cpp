class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int minRange=b[0][0],maxRange=b[0][1];
        cout<<minRange<<" "<<maxRange<<endl;
        for(int i=1;i<o.size();++i){
            int currDiff=o[i]-o[i-1];
            minRange=max(minRange+currDiff,b[i][0]);
            maxRange=min(maxRange+currDiff,b[i][1]);
            if(minRange>maxRange) return 0;
        }
        return maxRange-minRange+1;
    }
};