class Solution {
public:
    #define MOD 1000000007
    typedef long long ll;

    ll expo(ll a,ll b, ll m=MOD){ 
        if(b==0) return 1%m;
        if(b%2==0){
            int t=expo(a,b/2);
            return (1LL*t*t%m); 
        }
        else{
            int t=expo(a,(b-1)/2); 
            t=(1LL*t*t)%m;
            return (1LL*a*t)%m; 
        } 
    }

    // typedef long long ll;
    vector<ll> fact;
    vector<ll> invFact;

    void precomputefactorials(ll n){
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i) % MOD; // O(n)
        
        invFact[n]=expo(fact[n],MOD-2); // (1/n!) % MOD = (n!)^MOD-2 % MOD 
        for(int i=n-1;i>=0;i--) invFact[i]=(invFact[i+1]*(i+1)) % MOD; // O(n)
    }

    ll nCr(ll n,ll r){
        if(r<0 || r>n) return 0;
        return ((fact[n]*invFact[r]) % MOD*invFact[n-r]) % MOD;
    }

    int dp[82][725][82];
    int f(int idx,int sum,int cnt,int tSum,string &str){
        if(idx>=str.length()){
            return sum==tSum/2 && cnt==str.length()/2;
        }

        int &ans=dp[idx][sum][cnt];
        if(ans!=-1) return ans;

        int digit=str[idx]-'0';
        int notTake=f(idx+1,sum,cnt,tSum,str);
        int take=f(idx+1,sum+digit,cnt+1,tSum,str);

        return ans=(notTake+take)%MOD;
    }

    int countBalancedPermutations(string num) {
        int tSum=0;
        for(int i=0;i<num.length();++i){
            tSum+=(num[i]-'0');
        } 

        if(tSum&1) return 0; // if tSum is odd, hence the sum cannot be divided into halves

        int halfLen=num.length()/2;

        precomputefactorials(num.length()+2);

        memset(dp,-1,sizeof(dp));
        ll ways=f(0,0,0,tSum,num);

        ll ans=(((ways*fact[halfLen])%MOD)*fact[num.length()-halfLen])%MOD; // ways*((oddSpots!)*(evenSpots!))

        //removing duplicate permutations
        vector<int> freq(10,0);
        for(int i=0;i<num.length();++i){
            freq[num[i]-'0']++;
        }

        for(int i=0;i<freq.size();++i){
            ans=(ans*invFact[freq[i]])%MOD;
        }

        return ans;
    }
};