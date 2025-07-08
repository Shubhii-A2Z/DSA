class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx,int k,vector<vector<int>> &events){
        if(idx>=events.size() || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int i;
        for(i=idx+1;i<events.size();i++)
            if(events[i][0] > events[idx][1])
                break;
        return dp[idx][k]=max(solve(idx+1,k,events),events[idx][2]+solve(i,k-1,events));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        dp.clear();
        dp.resize(events.size()+1,vector<int>(k+1,-1));
        sort(begin(events),end(events),[&](auto a,auto b){
            return a[0]<b[0];
        });
        return solve(0,k,events);
    }
};