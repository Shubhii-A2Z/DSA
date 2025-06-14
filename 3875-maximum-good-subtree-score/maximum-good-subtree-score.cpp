class Solution {
public:
    #define MOD 1000000007
    typedef long long ll;

    unordered_map<int,vector<int>> gr;
    unordered_map<int,vector<int>> subTree;

    ll dp[505][1026]; //[index][mask]

    void dfs(int node,int root,vector<int> &vals){
        subTree[root].push_back(vals[node]);
        for(auto &ch:gr[node]){
            dfs(ch,root,vals);
        }
    }

    // returns bitmask of digits in a number, or -1 if the number has repeated digits
    int merge(int mask,int val){
        while(val){
            int dig=val%10;
            if(mask&(1<<dig)) return -1; // digits repeated
            mask|=(1<<dig);
            val/=10;
        }
        return mask;
    }

    ll f(int i,int mask,vector<int> &v){
        if(i>=v.size()) return 0;
        if(dp[i][mask]!=-1) return dp[i][mask];

        ll notTake=f(i+1,mask,v);
        ll take=0;

        int newMask=merge(mask,v[i]);
        if(newMask!=-1){
            take=(v[i]+f(i+1,newMask,v))%MOD;
        }
        
        return dp[i][mask]=max(take,notTake);
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n=par.size();

        for(int i=0;i<par.size();++i){
            gr[par[i]].push_back(i);
        }

        int ans=0;
        for(int i=0;i<n;++i){
            dfs(i,i,vals); // finds all the subTree nodes' values of current node 'i'
            memset(dp,-1,sizeof(dp));
            ll val=f(0,0,subTree[i]); // simply apply take/notTake dp on subset values
            ans=(ans+val)%MOD; // add the score of current node
        }
        
        return ans;
    }
};