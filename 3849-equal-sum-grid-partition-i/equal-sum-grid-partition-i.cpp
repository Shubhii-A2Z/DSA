class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll tSum=0;
        for(auto &v:grid){
            tSum+=(accumulate(begin(v),end(v),0LL));
        }

        ll currSum=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                currSum+=grid[i][j];
            }
            if(2*currSum==tSum) return true;
        }

        currSum=0;
        for(int i=0;i<grid[0].size();++i){
            for(int j=0;j<grid.size();++j){
                currSum+=grid[j][i];
            }
            if(2*currSum==tSum) return true;
        }

        return false;
    }
};