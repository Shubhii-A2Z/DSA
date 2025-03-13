class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        auto check=[&](int mid)->bool{
            vector<int> q(nums.size(),0), v=nums;
            for(int i=0;i<mid;++i){
                int l=queries[i][0], r=queries[i][1], val=queries[i][2];
                q[l]-=val;
                r+1<v.size() ? q[r+1]+=val : 1;
            }
            for(int i=1;i<q.size();++i) q[i]+=q[i-1];
            for(int i=0;i<q.size();++i) {
                v[i]+=q[i];
                if(v[i]>0) return false;
            }
            return true;
        };

        int lo=0, hi=queries.size(), ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};