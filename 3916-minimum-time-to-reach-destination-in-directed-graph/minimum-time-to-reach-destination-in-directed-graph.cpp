class Solution {
public:
    struct state{
        int a,b,c; //{v,st,ed}
    };  

    unordered_map<int,vector<state>> gr;
    typedef long long ll;
    typedef pair<ll,ll> pr;

    ll shortestPath(int n,ll src, ll dest) {

        priority_queue<pr,vector<pr>,greater<pr>> pq;
        vector<ll> dist(n+1,INT_MAX);
        dist[src]=0;
        pq.push({0,src}); //{time,node}

        while(pq.size()){
            int currTime=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();

            if(currTime>dist[currNode]) continue;
            if(currNode==dest) return currTime;

            for(auto &[nbr,st,ed]:gr[currNode]){
                if(currTime>ed) continue;
                else if(currTime<st){
                    if(st+1<dist[nbr]){
                        dist[nbr]=st+1;
                        pq.push({st+1,nbr});
                    }
                }
                else{
                    if(currTime+1<dist[nbr]){
                        dist[nbr]=currTime+1;
                        pq.push({currTime+1,nbr});
                    }
                }
            }
        }
        
        return dist[dest]==INT_MAX ? -1 : dist[dest];
    }

    int minTime(int n, vector<vector<int>>& edges) {
        for(auto &e:edges){
            int u=e[0], v=e[1], st=e[2], ed=e[3];
            gr[u].push_back({v,st,ed});
        }

        return shortestPath(n,0,n-1);
    }
};