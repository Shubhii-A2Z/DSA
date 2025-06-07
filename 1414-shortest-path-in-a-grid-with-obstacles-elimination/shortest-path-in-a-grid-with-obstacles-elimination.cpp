class Solution {
public:
    struct state{
        int a,b,c; //{cell_i, cell_j, eliminating power left}
    };  

    vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();

        int vis[41][41][1601]{}; // visited array will now contain three states
        queue<state> q;
        q.push({0,0,k});

        int steps=0;
        while(q.size()){
            int sze=q.size();
            while(sze--){
                auto curr=q.front(); q.pop();
                int i=curr.a, j=curr.b, power=curr.c;

                if(i==n-1 && j==m-1) return steps;

                for(auto &d:dir){
                    int i_=i+d.first, j_=j+d.second;
                    if(i_>=n || i_<0 || j_>=m || j_<0) continue;
                    if(grid[i_][j_]==0 && !vis[i_][j_][power]){
                        q.push({i_,j_,power});
                        vis[i_][j_][power]=true;
                    }
                    else if(grid[i_][j_]==1 && power>0 && !vis[i_][j_][power-1]){
                        q.push({i_,j_,power-1});
                        vis[i_][j_][power-1]=true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};