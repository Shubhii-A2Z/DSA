class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        auto SortFromRow=[&](int i){
            vector<int> temp;
            for(int r=i,c=0 ; r<n && c<m ; ++r,++c){
                temp.push_back(grid[r][c]);
            }
            sort(begin(temp),end(temp),greater<int>());
            for(int r=i,c=0,k=0 ; r<n && c<m ; ++r,++c,++k){
                grid[r][c]=temp[k];
            }
        };  

        auto SortFromCol=[&](int i){
            vector<int> temp;
            for(int r=0,c=i ; r<n && c<m ; ++r,++c){
                temp.push_back(grid[r][c]);
            }
            sort(begin(temp),end(temp));
            for(int r=0,c=i,k=0 ; r<n && c<m ; ++r,++c,++k){
                grid[r][c]=temp[k];
            }
        };

        for(int i=1;i<n;++i) SortFromCol(i);
        for(int j=0;j<m;++j) SortFromRow(j);

        return grid;
    }
};