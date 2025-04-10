class Solution {
public:
    #define debug(x) cout<<#x<<"="<<x<<"\n"
    typedef long long ll;
    ll dp[16][2];
    ll f(string &str,ll idx,ll tight,int maxAllowed,string &suffix){
        if(idx==str.length()) return 1;
        if(dp[idx][tight]!=-1) return dp[idx][tight];
        ll ans=0;
        int limit=tight?str[idx]-'0':9;
        limit=min(limit,maxAllowed);

        int suffixIdx=str.length()-suffix.length();
        if(idx>=suffixIdx){
            //case 1:tight is false
            if(tight==false){
                return dp[idx][tight]=1;
            }
            //case2:number suffix > req. suffix
            if(str[idx]>suffix[idx-suffixIdx]){
                return dp[idx][tight]=1;
            }
            //case 3
            if(str[idx]==suffix[idx-suffixIdx]){
                return dp[idx][tight]=f(str,idx+1,true,maxAllowed,suffix);
            }
            //case 4
            if(str[idx]<suffix[idx-suffixIdx]){
                return dp[idx][tight]=0;
            }
        }
        else{
            for(int i=0;i<=limit;i++){
                ll newTight=tight&(i==str[idx]-'0');
                ans+=f(str,idx+1,newTight,maxAllowed,suffix);
            }
        }
        return dp[idx][tight]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int maxAllowed, string suffix) {
        string l=to_string(start-1);
        ll ans1=0;
        if(l.length()>=suffix.length()){
            memset(dp,-1,sizeof(dp));
            ans1=f(l,0,true,maxAllowed,suffix);
        }
        string hi=to_string(finish);
        ll ans2=0;
        memset(dp,-1,sizeof(dp));
        ans2=f(hi,0,true,maxAllowed,suffix);
        return ans2-ans1;

    }
};