class Solution {
public:
    int dp[305][1005][12];
    int f(int i,int maxD,int d,vector<int>& v){
        if(i>=v.size()){
            return d ? INT_MAX/2 : maxD;
        }
        if(d==0){
            int maxe=0;
            for(int j=i;j<v.size();++j){
                maxe=max(maxe,v[j]);
            }
            return maxe;
        }

        if(dp[i][maxD][d]!=-1) return dp[i][maxD][d];

        int currMx=max(maxD,v[i]);
        int ans1=f(i+1,currMx,d,v);
        int ans2=currMx+f(i+1,0,d-1,v);

        return dp[i][maxD][d]=min(ans1,ans2);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        memset(dp,-1,sizeof(dp));
        return f(0,0,d,jobDifficulty);
    }
};