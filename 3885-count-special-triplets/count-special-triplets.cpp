class Solution {
public:
    #define MOD 1000000007
    int specialTriplets(vector<int>& nums) {

        unordered_map<int,vector<int>> fq;

        for(int i=0;i<nums.size();++i){
            int ele=nums[i];
            fq[ele].push_back(i);
        }

        int cnt=0;
        for(int j=1;j<nums.size()-1;++j){
            int ele=nums[j];
            auto &v=fq[2*ele]; // indices where 2*ele is present
            if(v.size()<=1) continue;

            int idx=lower_bound(begin(v),end(v),j)-begin(v);
            if(idx==v.size()) continue;

            int leftFq=idx, rightFq=(v[idx]!=j ?  v.size()-idx : v.size()-idx-1);
            // cout<<leftFq<<' '<<rightFq<<endl;
            cnt=(cnt+(1LL*leftFq*rightFq)%MOD)%MOD;
        }

        return cnt;
    }
};