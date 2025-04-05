class Solution {
public:
    int dp[16][(1<<16)];
    int f(int i,int mask,int n){
        if(i>n) return 1;

        int &ans=dp[i][mask];
        if(ans!=-1) return ans;

        int cnt=0;
        for(int num=1;num<=n;++num){
            if(mask&(1<<num)) continue;
            if(num%i==0 || i%num==0) cnt+=f(i+1,mask|(1<<num),n);
        }
        return ans=cnt;
    }

    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return f(1,0,n);
    }
};