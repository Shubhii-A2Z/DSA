class Solution {
public:
    #define MOD 1000000007
    int dp[1005][2][12];

    string convert(string num, int b) {
        if (num == "0") return "0";
        string res = "";
        while (num != "") {
            string next = "";
            int rem = 0;
            for (int i = 0; i < num.size(); i++) {
                int cur = rem * 10 + (num[i] - '0');
                int div = cur / b;
                rem = cur % b;
                if (!next.empty() || div != 0) {
                    next += (div + '0');
                }
            }
            res = char(rem + '0') + res;
            num = next;
        }
        return res;
    }

    bool checkForLo(string lo){
        for(int i=1;i<lo.length();++i){
            if(lo[i]<lo[i-1]) return false;
        }
        return true;
    }

    int f(int idx,bool tight,int prev,string &s,int b){
        if(idx>=s.length()) return 1;

        int &ans=dp[idx][tight][prev];
        if(ans!=-1) return ans;

        int limit=tight ? s[idx]-'0' : b-1; // here the max limit of a digit is not '9', instead its (b-1), since its represented in base "b"

        int cnt=0;
        for(int i=prev;i<=limit;++i){ // number should be non-decreasing
            bool newTight=tight&&(i==limit);
            cnt=(cnt+f(idx+1,newTight,i,s,b))%MOD;
        }

        return ans=cnt;
    }

    int countNumbers(string l, string r, int b) {
        string lo=convert(l,b);
        string hi=convert(r,b);

        memset(dp,-1,sizeof(dp));
        int val1=f(0,1,0,hi,b);
        memset(dp,-1,sizeof(dp));
        int val2=f(0,1,0,lo,b);

        return (val1-val2+checkForLo(lo)+MOD)%MOD; // instead of finding for (lo-1) we're seperately checking for "lo" value, also since the values r modded hence its possible that val1<val2, so we add MOD to make its positive again
    }
};