class Solution {
public:
    int dp[101][101];
    int n,m,N;
    
    bool f(int i,int j,string &s1,string &s2,string &s3){
        if(i==n && j==m && i+j==N) return true;
        if(i+j==N) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool res=false;
        if(s1[i]==s3[i+j]) res=f(i+1,j,s1,s2,s3);
        if(res) return dp[i][j]=res;
        if(s2[j]==s3[i+j]) res=f(i,j+1,s1,s2,s3);
        return dp[i][j]=res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        n=s1.length();
        m=s2.length();
        N=s3.length();
        return f(0,0,s1,s2,s3);
    }
};