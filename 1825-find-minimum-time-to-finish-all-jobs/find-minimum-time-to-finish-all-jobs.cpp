class Solution {
public:
    int dp[(1<<12)+1][13];
    int subsetSum[(1<<12)+1]{};

    int f(int mask,int k,int n){
        if(mask==(1<<n)-1) return 0; // all jobs have been assigned

        if(dp[mask][k]!=-1) return dp[mask][k];

        int remaining=((1<<n)-1)^mask; // finding mask of jobs which havent been assigned yet
        if(k==1) return subsetSum[remaining]; // last worker takes all unassigned jobs


        int ans=INT_MAX;
        for(int sub=remaining;sub;sub=(sub-1)&remaining){ // iterating over the subsets of remaining
            int currTime=subsetSum[sub];
            ans=min(ans,max(currTime,f(mask|sub,k-1,n)));
        }

        return dp[mask][k]=ans;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();

        for(int mask=0;mask<(1<<n);++mask){ // Precomputing all subset sum
            int tSum=0;
            for(int i=0;i<n;++i){
                if(mask&(1<<i)) tSum+=jobs[i];
            }
            subsetSum[mask]=tSum;
        }

        memset(dp,-1,sizeof(dp));
        return f(0,k,n);
    }
};