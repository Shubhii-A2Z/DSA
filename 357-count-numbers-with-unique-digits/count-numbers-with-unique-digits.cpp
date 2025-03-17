class Solution {
public:
    int dp[10][2][(1<<10)][2];
    int f(int idx,bool tight,long long mask,string &s,bool isLeadingZero){
        if(idx>=s.length()){
            return 1;
        }
        int &res=dp[idx][tight][mask][2];
        if(res!=-1) return res;
        int limit=tight ? s[idx]-'0' : 9;
        int ans=0;
        for(int i=0;i<=limit;++i){
            bool newTight=tight && (i==limit);
            if(isLeadingZero && i==0){
                ans+=(f(idx+1,newTight,mask,s,true));
            }
            else{
                if(mask&(1LL<<i)) continue;
                ans+=f(idx+1,newTight,mask|(1LL<<i),s,false);
            }
        }
        return res=ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        int num=pow(10,n)-1;
        string s=to_string(num);
        // cout<<s<<endl;
        memset(dp,-1,sizeof(dp));
        long long mask=0;
        return f(0,1,mask,s,true);
    }
};