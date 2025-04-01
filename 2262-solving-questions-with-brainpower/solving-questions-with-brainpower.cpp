class Solution {
public:
    typedef long long ll;
    ll dp[100002];

    long long mostPoints(vector<vector<int>>& q) {

        auto f=[&](auto &&f,int idx)->ll{
            if(idx>=q.size()) return 0;
            if(dp[idx]!=-1) return dp[idx];

            ll currPt=q[idx][0], brainPower=q[idx][1];
            ll take=INT_MIN, notTake=INT_MIN;

            take=currPt+f(f,idx+brainPower+1);
            notTake=f(f,idx+1);
            return dp[idx]=max(take,notTake);
        };
        
        memset(dp,-1,sizeof(dp));
        return f(f,0);
    }
};