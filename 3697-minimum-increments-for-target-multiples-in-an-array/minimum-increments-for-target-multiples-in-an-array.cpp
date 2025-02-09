class Solution {
public:
    typedef long long ll;
    ll dp[50005][17];
    ll lcmPrecomputed[17]{};

    vector<int> target,nums;
    ll targetCount, numsCount;

    ll computeLCM(ll x,ll y){
        return (x*y)/__gcd(x,y);
    }

    void precomputeLCM(){
        for(ll subset=1;subset<(1<<targetCount);++subset){ // all possible subsets of target elements
            lcmPrecomputed[subset]=1;
            for(int j=0;j<targetCount;++j){
                if(subset&(1<<j)) // take j in subset
                    lcmPrecomputed[subset]=computeLCM(lcmPrecomputed[subset],target[j]); // lcm of subset
            }
        }
    }

    ll ceil(ll x, ll y){
        return (x+y-1)/y;
    }

    ll f(ll i, ll mask){
        if(mask==(1<<targetCount)-1) return 0; // all target elements have been considered 4
        if(i==numsCount) return 1e9; // all target elements not considered
        if(dp[i][mask]!=-1) return dp[i][mask];

        ll minOps=1e9;
        minOps=min(minOps,f(i+1,mask));

        for(int subset=1;subset<(1<<targetCount);++subset){
            ll subsetLCM=lcmPrecomputed[subset]; // lcm of subset
            ll justGreater=ceil(nums[i],subsetLCM)*subsetLCM; // justgreater than nums[i] which is a mutiple of lcm of subset

            minOps=min(minOps,(justGreater-nums[i])+f(i+1,mask|subset));
        }

        return dp[i][mask]=minOps;
    }

    int minimumIncrements(vector<int>& n, vector<int>& t) {
        nums=n; target=t;

        numsCount=nums.size();
        targetCount=target.size();

        precomputeLCM();

        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};