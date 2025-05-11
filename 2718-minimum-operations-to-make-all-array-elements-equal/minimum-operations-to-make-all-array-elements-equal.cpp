class Solution {
public:
    typedef long long ll;
    vector<long long> minOperations(vector<int>& v, vector<int>& q) {
        sort(begin(v),end(v));

        vector<ll> preSum(v.size());
        for(int i=0;i<v.size();++i){
            preSum[i]=i-1>=0 ? v[i]+preSum[i-1] : v[i];
        }

        vector<ll> ans;
        for(auto e:q){
            int idx=upper_bound(begin(v),end(v),e)-begin(v);
            if(idx==v.size()) idx--;
            if(idx==0) idx++;
            ll leftSum=preSum[idx-1], rightSum=preSum.back()-preSum[idx-1];

            ll leftSize=idx, rightSize=v.size()-idx;
            ll leftS=1LL*leftSize*e, rightS=1LL*rightSize*e;
            ll diff=abs(leftS-leftSum), diff2=abs(rightS-rightSum);
            ans.push_back(diff+diff2);
        }
        
        return ans;
    }
};