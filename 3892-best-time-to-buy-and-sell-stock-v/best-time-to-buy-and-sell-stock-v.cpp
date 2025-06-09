class Solution {
public:
    typedef long long ll;
    ll dp[1003][4][505];
    ll f(int i,int type,int k,vector<int> &prices){
        if(k==0) return 0;
        if(i>=prices.size()) return type==2 ? 0 : INT_MIN;

        ll &res=dp[i][type][k];
        if(res!=-1) return res;

        ll ans=f(i+1,type,k,prices); // eat fiveStar, do nothing :)

        if(!type){ //Normal transaction (prev bought)
            ll sell=prices[i]+f(i+1,2,k-1,prices);
            ans= max(ans,sell);
        }
        else if(type==1){ // Short selling transaction (prev sold)
            ll buy=-prices[i]+f(i+1,2,k-1,prices);
            ans= max(buy,ans);
        }
        else if(type==2) { // no transaction initiated (prev nothing done)
            ll buy=-prices[i]+f(i+1,0,k,prices);
            ll sell=prices[i]+f(i+1,1,k,prices);
            ans= max({ans,buy,sell});
        }

        return res=ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,2,k,prices);
    }
};