class Solution {
public:
    vector<vector<int>> dp;
    bool f(vector<int>& arr,int i,int k){
        if(k==0) return true;
        if(i==arr.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        if(arr[i]<=k){
            return dp[i][k]=f(arr,i+1,k-arr[i]) || f(arr,i+1,k);
        }
        else{
            return dp[i][k]=f(arr,i+1,k);
        }
    }
    bool canPartition(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0) return false;
        dp.clear();
        dp.resize(200,vector<int>(20005,-1));
        return f(arr,0,sum/2);
    }
};