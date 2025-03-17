class Solution {
public:
//     Memoization Using unordered_map<string, int>

// A unique key index + tight + sum + pro is stored in dp to avoid recomputation of overlapping subproblems.

// We are not using dp array because product of 9x9x9x9x.. 9times can lead to overflow.
    unordered_map<string,int> dp;
    int f(int idx,bool tight,int prod,int sum,string &s){
        if(idx>=s.length()){
            return sum>0 && prod%sum==0;
        }
        string key=to_string(idx)+"+"+to_string(tight)+"+"+to_string(prod)+"+"+to_string(sum);
        if(dp.count(key)) return dp[key];
        int limit=tight ? s[idx]-'0' : 9;
        int ans=0;
        for(int i=0;i<=limit;++i){
            bool newTight=tight&&(i==limit);
            int newProd=prod*i;
            if(sum+i==0) newProd=1;
            ans+=(f(idx+1,newTight,newProd,sum+i,s));
        }

        return dp[key]=ans; 
    }

    int beautifulNumbers(int l, int r) {
        string hi=to_string(r);
        int ans1=f(0,1,1,0,hi);

        string lo=to_string(l-1);
        dp.clear();
        int ans2=f(0,1,1,0,lo);

        return ans1-ans2;
    }
};