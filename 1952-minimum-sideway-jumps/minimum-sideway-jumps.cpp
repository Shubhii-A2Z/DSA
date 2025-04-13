class Solution {
public:
    int dp[500002][4];
    int f(int idx,int currLane,vector<int>& o){
        if(idx>=o.size()-1) return 0;
        if(o[idx]==currLane) return INT_MAX;

        int &res=dp[idx][currLane];
        if(res!=-1) return res;

        int ans=INT_MAX;
        if(o[idx+1]==currLane){
            for(int lane=1;lane<=3;++lane){
                if(lane!=currLane && o[idx]!=lane){
                    ans=min(ans,1+f(idx,lane,o));  // side jump at same index
                }
            }
        }
        else{
            ans=min(ans,0+f(idx+1,currLane,o));
        }

        return res=ans;
    }

    int minSideJumps(vector<int>& o) {
        memset(dp,-1,sizeof(dp));
        return f(0,2,o);
    }
};