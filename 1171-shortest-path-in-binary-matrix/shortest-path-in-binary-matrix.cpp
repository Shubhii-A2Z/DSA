class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;

        int n=grid.size(), m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1; // marking start node as visited
        int nodes=1; // considering initial node as 1st node

        while(q.size()){
            int sze=q.size();
            while(sze--){
                auto curr=q.front(); q.pop();
                int i=curr.first, j=curr.second;

                if(i==n-1 && j==m-1) return nodes;

                for(auto &d:dir){
                    int _i=i+d.first, _j=j+d.second;
                    if(_i<0 || _i>=n || _j<0 || _j>=m) continue;
                    if(grid[_i][_j]!=0) continue;
                    grid[_i][_j]=1;
                    q.push({_i,_j});
                }
            }
            nodes++;
        }

        return -1;
    }
};