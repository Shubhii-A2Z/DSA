class Solution {
public:
    int dp[71][5001];

    int f(int i, int currSum, vector<vector<int>> &mat, int target) {
        if(i == mat.size())
            return abs(currSum - target);
        
        if(dp[i][currSum] != -1)
            return dp[i][currSum];

        int ans = INT_MAX;
        for(int num : mat[i]) {
            ans = min(ans, f(i + 1, currSum + num, mat, target));
            if(ans == 0) break; // optimal answer found
        }
        return dp[i][currSum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, mat, target);
    }
};