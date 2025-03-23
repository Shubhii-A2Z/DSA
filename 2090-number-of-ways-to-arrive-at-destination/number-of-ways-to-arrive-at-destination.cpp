class Solution {
public:
    #define MOD 1000000007
    typedef long long ll;
    typedef pair<ll,ll> pr;
    unordered_map<ll,vector<pair<ll,ll>>> gr;

    int countPaths(int n, vector<vector<int>>& roads) {

        for(auto &r:roads){
            int u=r[0], v=r[1], wt=r[2];
            gr[u].push_back({v,wt});
            gr[v].push_back({u,wt});
        }

        priority_queue<pr,vector<pr>,greater<pr>> pq;
        vector<ll> dist(n,LLONG_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(pq.size()){
            auto [currDis,currNode]=pq.top();
            pq.pop();

            if(currDis>dist[currNode]) continue;

            for(auto &[nbr,nbrDis]:gr[currNode]){
                ll newDist=currDis+nbrDis;
                if(newDist<dist[nbr]){ // case1
                    dist[nbr]=newDist;
                    ways[nbr]=ways[currNode];
                    pq.push({newDist,nbr});
                }
                else if(newDist==dist[nbr]){
                    ways[nbr]=(ways[nbr]+ways[currNode])%MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};