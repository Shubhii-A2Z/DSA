
class Solution {
public:

    #define MOD 1000000007;
    typedef long long ll;

    class SegmentTree {    
    public:
        vector<ll> lzy;
        vector<ll> sum;
        vector<ll> sqr;
        int n;
        SegmentTree (int _n) : n(_n) {
            lzy.resize(4*n, 0);
            sum.resize(4*n, 0);
            sqr.resize(4*n, 0);
        }
        
        void update_lzy(int l, int r, int val) {
            if (l != r) {
                lzy[val*2+1] += lzy[val];
                lzy[val*2+2] += lzy[val];
            }
            ll gap = r-l+1;
            ll new_sum = sum[val] + lzy[val]*gap;
            ll new_sqr = sqr[val] + lzy[val]*sum[val]*2 + lzy[val]*lzy[val]*gap;
            
            sum[val] = new_sum % MOD;
            sqr[val] = new_sqr % MOD;
            lzy[val] = 0;
        }
        
        void AddOne (int x, int y, int l = 0, int r = -1, int i = 0) {
            if (r == -1) r += n;
            update_lzy(l, r, i);
            
            if (r < x || l > y) return;
            if (l >= x && r <= y) {
                lzy[i] = 1;
                return update_lzy(l, r, i);
            }
            
            int m = (l+r) >> 1;
            AddOne (x, y, l, m, i*2+1);
            AddOne (x, y, m+1, r, i*2+2);
            
            sum[i] = (sum[i*2+1] + sum[i*2+2]) % MOD;
            sqr[i] = (sqr[i*2+1] + sqr[i*2+2]) % MOD;
        }    
    };

    int sumCounts(vector<int>& nums) {
        SegmentTree segTree(nums.size());
        unordered_map<int,int> lastSeen;
        int result=0;
        for(int i=0;i<nums.size();++i){
            int st=lastSeen.count(nums[i]) ? lastSeen[nums[i]]+1 : 0; // starting index of range
            int ed=i; // ending index of range
            segTree.AddOne(st,ed); // add 1 in range [st,ed]
            result=(result+segTree.sqr[0])%MOD; // sqr[0] contains the final sum of squares of the frequency array
            lastSeen[nums[i]]=i;
        }
        return result;
    }
};