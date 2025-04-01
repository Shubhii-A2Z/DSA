class Solution {
public:
    #define MOD 1000000007
    int dp[52][1001];

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        auto f=[&](auto &&f,int i,int pts)->int{
            if(pts>target) return 0;
            if(i>=types.size()) return pts==target;

            int &ans=dp[i][pts];
            if(ans!=-1) return ans;

            int val1=0, val2=0;

            int noOfQn=types[i][0];
            for(int k=1;k<=noOfQn;++k){
                val1=(val1+f(f,i+1,pts+k*types[i][1]))%MOD; // solve k no. of qns of i type
            }
            val2=(val2+f(f,i+1,pts))%MOD; // leave this qn

            return ans=(val1+val2)%MOD;
        };

        memset(dp,-1,sizeof(dp));
        return f(f,0,0);
    }
};