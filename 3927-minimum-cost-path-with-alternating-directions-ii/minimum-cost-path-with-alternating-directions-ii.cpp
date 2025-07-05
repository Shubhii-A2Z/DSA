class Solution {
public:
    typedef long long ll;
    typedef pair<ll,pair<ll,ll>> pr;

    vector<pair<int,int>> dir={{1,0},{0,1}};

    ll shortestPath(int n,int m,vector<vector<int>>& waitCost) {

        priority_queue<pr,vector<pr>,greater<pr>> pq;
        vector<vector<ll>> dist(n,vector<ll>(m,LLONG_MAX));
        dist[0][0]=1;
        pq.push({1,{0,0}});

        while(pq.size()){
            auto curr=pq.top(); pq.pop();
            ll currCost=curr.first, i=curr.second.first, j=curr.second.second;

            if(currCost>dist[i][j]) continue;
            if(i==n-1 && j==m-1) return currCost-waitCost[i][j]; // reached the dest, remove the extra waitCost

            /* The total cost of reaching a cell becomes sum(steps of 2 seconds)
             because we need to go and wait. (Expect the first and final position.)
            In other words, we always add (nx + 1) * (ny + 1) + waitCost[nx][ny] when we want to go to next node.
            */

            if(i+1<n){ // down
                ll newCost=currCost+(i+2)*(j+1)+waitCost[i+1][j];
                if(newCost<dist[i+1][j]){
                    dist[i+1][j]=newCost;
                    pq.push({newCost,{i+1,j}});
                }
            }
            if(j+1<m){ // right
                ll newCost=currCost+(i+1)*(j+2)+waitCost[i][j+1];
                if(newCost<dist[i][j+1]){
                    dist[i][j+1]=newCost;
                    pq.push({newCost,{i,j+1}});
                }
            }
        }
        
        return dist[n-1][m-1]==INT_MAX ? -1 : dist[n-1][m-1];
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        return shortestPath(m,n,waitCost);
    }
};