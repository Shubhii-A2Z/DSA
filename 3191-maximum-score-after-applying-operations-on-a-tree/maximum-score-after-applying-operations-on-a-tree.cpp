class Solution {
public:

    /* ----- standard dp on trees qn -------

        here, at every node we have two choices -> take/notTake

        Approach 1) find the pathSum for every root in O(n), then apply standard take/notTake dp, while maintaining the current pathSum.
                    For the root node, we can only take it if the current pathSum + val[leaf] != pathSum[leaf].
                    For evry node, we'll keep adding the values of take/notTake for its subtree, and at end, return max of both.
                    (for Reference to this code, check my submission of TLE)
        
        Approach 2) Since the values[node]<=1e9, hence we cant take pathSum as dp state.
                    So now, since the qns says that we can't take all the nodes in a root-leaf path, hence for a node we have 2 choices.
                    If we take a node, we'll maintain a bool "isSkipped", stating that a node has been taken.
                    At the leaf Node, if "isSkipped" value is true, it means we can't take current node
                    Hence by this, we won't need the pathSum state, since the above itself checkes that the conditions r satisfied.
                    (for Reference to this code, check my submission of submitted)
    */

    typedef long long ll;

    unordered_map<int,vector<int>> tree;
    vector<int> val;

    ll dp[20002][2];

    ll f(int node,bool nodeSkipped,int par){
        if(par!=-1 && tree[node].size()==1){ // node is leaf
           return nodeSkipped ? val[node] : 0; // if any node in the root-to-left path is skipped, then only the leaf node can be taken
        }

        if(dp[node][nodeSkipped]!=-1) return dp[node][nodeSkipped];

        ll notTake=0, take=val[node]; //{leave current node, taking current node}

        for(auto &child:tree[node]){
            if(child==par) continue;
            notTake+=f(child,true,node); // node is skipped, make the bool value as true
            take+=f(child,nodeSkipped,node); // pass the bool value as it is
        }

        return dp[node][nodeSkipped]=max(take,notTake);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        for(auto &e:edges){
            int u=e[0], v=e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        val=values;

        memset(dp,-1,sizeof(dp));
        return f(0,false,-1);
    }
};