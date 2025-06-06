class Solution {
public:
    struct state{
        int a,b,c,d; //{litter mask,energy,i,j}
    };  

    vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1}};

    int minMoves(vector<string>& grid, int energy) {
        int n=grid.size(), m=grid[0].size();
        map<pair<int,int>,int> mp;

        int x,y, tLen=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                char ch=grid[i][j];
                if(ch=='S'){
                    x=i; y=j;
                }
                if(ch=='L'){
                    mp[{i,j}]=tLen++;
                }
            }
        }

        queue<state> q;
        q.push({0,energy,x,y});
        int dp[23][23][(1<<11)+5]{}; //Now, in BFS, we always need a visited structure to avoid infinite loops. Here, we will maintain a dp[x][y][mask] that stores the maximum energy we have when reaching this state. If our current energy is less than this value, we will simply ignore that state and not push it into the queue, otherwise we'll update our dp table & push it into the queue.
        dp[x][y][0]=energy;

        int steps=0, count=0;
        while(q.size()){
            int sze=q.size();
            while(sze--){
                auto curr=q.front(); q.pop();
                int mask=curr.a, currEnergy=curr.b, i=curr.c, j=curr.d;

                if(mask==(1<<tLen)-1) return steps;

                for(auto &d:dir){
                    int i_=i+d.first, j_=j+d.second;
                    if(i_>=n || i_<0 || j_>=m || j_<0) continue;

                    char ch=grid[i_][j_];
                    if(ch=='X') continue;

                    int newMask=mask, newEnergy=currEnergy-1;
                    if(ch=='L') newMask|=(1<<mp[{i_,j_}]);
                    if(newMask==(1<<tLen)-1) return steps+1;
                    
                    if(ch=='R') newEnergy=energy;

                    if(newEnergy<=dp[i_][j_][newMask]) continue;
                    if(newEnergy==0) continue;

                    dp[i_][j_][newMask]=newEnergy;
                    q.push({newMask,newEnergy,i_,j_});
                }
            }
            steps++;
        }

        return -1;
    }
};