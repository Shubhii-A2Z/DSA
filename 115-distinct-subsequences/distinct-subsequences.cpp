class Solution {
public:
    int dp[1005][1005];
    int f(int i,int j,string &s,string &t){
        if(j==t.length()) return 1; // All characters in t are matched
        if(i==s.length()) return 0; // s is exhausted but t is not matched fully
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans+=f(i+1,j+1,s,t);
            ans+=f(i+1,j,s,t);
        }
        else{
            ans+=f(i+1,j,s,t);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        if(s.length()<t.length()) return 0;
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,t);
    }
};