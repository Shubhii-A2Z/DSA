class Solution {
public:
    
    typedef long long ll;
    typedef pair<ll,ll> pr;

    ll shortestPath(ll src, ll dest,vector<int> &nums) {

        queue<pr> q;
        unordered_set<ll> vis;

        q.push({0,src});

        while(q.size()){
            int currSze=q.size();
            while(currSze--){
                auto [cost,currNode]=q.front();
                q.pop();

                if(currNode==dest) return cost;
                
                if(currNode<0 || currNode>1000 || vis.count(currNode)) continue;
                vis.insert(currNode);

                for(auto &e:nums){
                    vector<ll> nextVals={currNode+e,currNode-e,currNode^e};
                    for(auto &next:nextVals) q.push({cost+1,next});
                }
            } 
        }

        return -1;
    }

    int minimumOperations(vector<int>& nums, int start, int goal) {
        return shortestPath(start,goal,nums);
    }
};