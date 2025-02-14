class Solution {
public:
    typedef long long ll;
    unordered_map<int,vector<int>> graph;
    vector<ll> maxIn, maxOut;
    vector<int> prices;

    ll InDfs(int node,int par){
        ll &result=maxIn[node];
        for(auto &child:graph[node]){
            if(child==par) continue;
            result=max(result,InDfs(child,node));
        }
        result+=prices[node];
        return result;
    }

    void OutDfs(int node,int par){
        multiset<ll> all_in_from;
        for(auto &child:graph[node]){
            if(child==par) continue;
            all_in_from.insert(maxIn[child]);
        }

        for(auto &child:graph[node]){
            if(child==par) continue;
            all_in_from.erase(all_in_from.find(maxIn[child]));
            ll max_from_others=all_in_from.size()==0 ? 0 : *all_in_from.rbegin();
            maxOut[child]=max(max_from_others,maxOut[node])+prices[node];
            all_in_from.insert(maxIn[child]);
            OutDfs(child,node);
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        maxIn.resize(n); maxOut.resize(n);
        prices=price;
        for(auto &itr:edges){
            int u=itr[0], v=itr[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        InDfs(0,-1);
        OutDfs(0,-1);

        ll res=0;
        for(int root=0;root<n;++root){
            ll ans=max(maxIn[root],maxOut[root]+price[root])-price[root]; //max path sum - min path sum
            res=max(res,ans);
        }

        return res;
    }
};