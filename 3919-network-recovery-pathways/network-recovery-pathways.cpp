class Solution {
public:

    /*
    *   Return the "maximum" path score  ==>  maximum "minimum-edge cost" among all valid paths  ===> Binary Search
    *   Binary Search On weights
    */

    typedef long long ll;
    typedef pair<ll,ll> pr;
    unordered_map<int,vector<pr>> gr;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size()-1;
        ll maxWt=-1;

        for(auto &e:edges){
            int u=e[0], v=e[1], wt=e[2];
            gr[u].push_back({v,wt});
            n=max({n,u,v});
            maxWt=max(maxWt,1LL*wt);
        }

        auto dij=[&](ll minEdge)->bool{
            priority_queue<pr,vector<pr>,greater<pr>> pq; //{dist,node}
            vector<ll> dist(n+2,LLONG_MAX);

            pq.push({0,0});
            dist[0]=0;

            while(pq.size()){
                auto curr=pq.top(); pq.pop();
                ll currDist=curr.first, currNode=curr.second;

                if(currDist>dist[currNode] || currDist>k) continue;
                if(currNode==n) return true;

                for(auto &itr:gr[currNode]){
                    int nbr=itr.first, wt=itr.second;

                    if(online[nbr]==false) continue; // Node is "offline", hence can't traverse
                    if(wt<minEdge) continue; // we can't traverse any edge less than minEdge

                    ll newDist=currDist+wt;
                    if(newDist<dist[nbr]){
                        dist[nbr]=newDist;
                        pq.push({newDist,nbr});
                    }
                }
            }

            return false;
        };

        ll lo=0, hi=maxWt, ans=-1;
        while(lo<=hi){
            ll mid=lo+((hi-lo)>>1);
            if(dij(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;

    }
};