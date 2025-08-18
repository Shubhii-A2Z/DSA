class Solution {
public:
    typedef pair<int,int> pr;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>> gr, revGr;
        for(auto &e:edges){
            int u=e[0], v=e[1], wt=e[2];
            gr[u].push_back({v,wt});
            revGr[v].push_back({u,2*wt});
        }

        vector<bool> isUsed(n,false);
        vector<int> dist(n,INT_MAX);

        priority_queue<pr,vector<pr>,greater<pr>> pq; //{dist,node}
        pq.push({0,0});

        while(pq.size()){
            auto [currDist,currNode]=pq.top(); pq.pop();

            if(dist[currNode]<currDist) continue;
            if(currNode==n-1) return currDist;

            for(auto &itr:gr[currNode]){
                int nbr=itr[0], wt=itr[1];
                int newDist=currDist+wt;
                if(dist[nbr]>newDist){
                    dist[nbr]=newDist;
                    pq.push({newDist,nbr});
                }
            }

            for(auto &itr:revGr[currNode]){
                int nbr=itr[0], wt=itr[1];
                int newDist=currDist+wt;
                if(dist[nbr]>newDist){
                    dist[nbr]=newDist;
                    pq.push({newDist,nbr});
                }
            }
        }

        return -1;
    }
};