class Solution {
public:
    typedef pair<int,pair<int,pair<int,int>>> pr;
    vector<pair<int,int>> dir={{0,-1},{-1,0},{0,1},{1,0}};

    int dijkstra(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;

        priority_queue<pr,vector<pr>,greater<pr>> pq; //{time,{steps,{row,col}}}
        pq.push({0,{0,{0,0}}});
        int ans;

        while(pq.size()>0){
            int time=pq.top().first;
            int steps=pq.top().second.first;
            int row=pq.top().second.second.first;
            int col=pq.top().second.second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                ans=time;
                break;
            }
            for(int d=0;d<4;d++){
                int newR=row+dir[d].first;
                int newC=col+dir[d].second;
                if(newR<0 || newR>=n || newC<0 || newC>=m ) continue;
                int maxTime=max(time,grid[newR][newC])+(steps&1 ? 2 : 1); // +1 is 1 second it takes for moving in that room
                if(maxTime<dist[newR][newC]){
                    dist[newR][newC]=maxTime;
                    pq.push({maxTime,{steps+1,{newR,newC}}});
                }
            }
        }

        return ans;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        return dijkstra(moveTime);
    }
};