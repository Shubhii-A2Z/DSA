class Solution {
public:
    // standard "front partition" dp

    typedef long long ll;
    ll dp[502];

    ll f(int i,int k,vector<int> &arr){
        if(i>=arr.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        ll maxe=-1, sum=0, maxSum=0;
        for(int j=i;j<min((int)arr.size(),i+k);++j){ // applying partition from i->i+k
            maxe=max(maxe,1LL*arr[j]); // max ele of this subarray
            sum=1LL*maxe*(j-i+1)+f(j+1,k,arr);
            maxSum=max(maxSum,sum); // max sum out of all possible partitions
        }

        return dp[i]=maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,arr);
    }
};