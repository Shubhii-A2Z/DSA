class Solution {
public:
    struct Edge{
        int neighbour;
        int wt;
        Edge(int neighbour,int wt):neighbour(neighbour),wt(wt){}
    };
    
    typedef long long ll;
    vector<vector<ll>> dp;
    vector<vector<Edge>> graph;
    int K;

    ll solve(int node,int isParEdgeRemoved,int parent){
        if(dp[node][isParEdgeRemoved]!=-1) return dp[node][isParEdgeRemoved];

        int edgesToRemove=max(0,int(graph[node].size())-K-isParEdgeRemoved);
        vector<pair<ll,ll>> candidates;

        for(auto &[ne,wt]:graph[node]){
            if(ne!=parent){
                ll notRemove=solve(ne,0,node)+wt;
                ll remove=solve(ne,1,node);
                candidates.push_back({notRemove,remove});
            }
        }

        sort(begin(candidates),end(candidates),[&](auto &p1,auto &p2){
            return (p1.first-p1.second)<(p2.first-p2.second);
        });

        ll answer=0;
        for(int i=0;i<candidates.size();++i){
            ll notRemove=candidates[i].first;
            ll remove=candidates[i].second;
            if(i<edgesToRemove) answer+=remove;
            else answer+=(max(remove,notRemove));
        }
        
        return dp[node][isParEdgeRemoved]=answer;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size()+1;
        K=k;
        graph.resize(n);
        dp.resize(n,vector<ll>(2,-1));
        for(auto &edge:edges){
            graph[edge[0]].push_back(Edge(edge[1],edge[2]));
            graph[edge[1]].push_back(Edge(edge[0],edge[2]));
        }
        return solve(0,0,-1);
    }
};