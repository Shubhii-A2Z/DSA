class Solution {
public:

//     Intution
// Basic idea is counting subsets with sum>= k but since nums[i]<=1e9 that will take too much time. Since we know k<=1000 we can count subsets with sum<=k.

// Counting subsets with both partitions having sum>=k is equivalent to counting subsets with ONE OF THE PARTITION with sum<k and subtracting it from total number of subsets(2^n).

    #define MOD 1000000007
    typedef long long ll;

    ll expo(ll a,ll b, ll m=MOD){ if(b==0) return 1%m; if(b%2==0){ int t=expo(a,b/2); return (1LL*t*t%m); }else{ int t=expo(a,(b-1)/2); t=(1LL*t*t)%m; return (1LL*a*t)%m; } } // for Calculating total number of subsets i.e. 2^n

    ll dp[1001][1001];

    int countPartitions(vector<int>& nums, int k) {

        if(accumulate(begin(nums),end(nums),0LL) < 2*k) return 0; // Checking if the sum of array > 2 * k,
        // array can never be partitioned if sum is less than 2 * k

        auto f=[&](auto &&f,int i,ll sum)->ll{ // this recursive dp gives total subsets with (sum < k)
            if(sum>=k) return 0;
            if(i>=nums.size()) return 1;

            ll &ans=dp[i][sum];
            if(ans!=-1) return ans;

            ll val1=0,val2=0;
            val1=(val1+f(f,i+1,sum))%MOD;
            val2=(val2+f(f,i+1,sum+nums[i]))%MOD;

            return ans=(val1+val2)%MOD;
        };

        memset(dp,-1,sizeof(dp));
        // After calculating the number of partitions with a sum less than k,
        // the solution multiplies the result by 2 to account for the fact
        // that the same partition can be counted as either the left group or
        // the right group.

        // For example, ([1,2,3],[4]) & ([4],[1,2,3]) should be counted separately
        // BUT the part function only considers ([4],[1,2,3])
        return (expo(2,nums.size())%MOD-2*f(f,0,0)%MOD+MOD)%MOD;
    }
};