class Solution {
public:
    #define MOD 1000000007

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int mask=0;
        for(int i=0;i<32;++i){
            if(n&(1<<i)){
                powers.push_back(mask|(1<<i));
            }
        }

        vector<int> ans;
        for(auto &q:queries){
            int l=q[0], r=q[1];
            int currProd=1;
            for(int idx=l;idx<=r;++idx){
                currProd=(1LL*currProd%MOD*powers[idx]%MOD)%MOD;
            }
            ans.push_back(currProd);
        }

        return ans;
    }
};