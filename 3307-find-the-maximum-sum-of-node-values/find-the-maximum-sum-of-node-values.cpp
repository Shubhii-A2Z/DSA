class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0,cnt=0,sacrificeVal=INT_MAX;
        for(int ele:nums){
            if((ele^k)>ele){
                sum+=(ele^k);
                sacrificeVal=min(sacrificeVal,1LL*((ele^k)-ele));
                cnt++; // increasing count of nodes whose val wnt to increase
            }
            else{
                sum+=ele;
                sacrificeVal=min(sacrificeVal,1LL*(ele-(ele^k)));
            }
        }
        if(cnt&1) return sum-sacrificeVal;
        return sum;
    }
};