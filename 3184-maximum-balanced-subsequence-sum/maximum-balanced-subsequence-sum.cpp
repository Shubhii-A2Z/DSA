class Solution {
public:
    typedef long long ll;
    
    #define pr pair<ll, ll>
    
    struct SegTree {
    public:
    
        SegTree (int _n) : n (_n) {
            tree.resize(4*n, 0);
        }
        
        ll query (int x, int y) {
            return query (x, y, 0, n-1, 0);
        }
        
        void update (int ind, ll val) {
            update (ind, val, 0, n-1, 0);
        }
    
    private:
        
        vector<ll> tree;
        int n;
        
        ll query (int x, int y, int l, int r, int i) {
            if (r < x || l > y) return 0;
            if (l >= x && r <= y) return tree[i];
            
            int m = (l+r) >> 1;
            return max(
                query (x, y, l, m, i*2+1),
                query (x, y, m+1, r, i*2+2)
            );
        }
        
        void update (int ind, ll val, int l, int r, int i) {
            if (l == r) {
                tree[i] = val;
                return;
            }
            
            int m = (l+r) >> 1;
            if (m >= ind) update (ind, val, l, m, i*2+1);
            else update (ind, val, m+1, r, i*2+2);
            
            tree[i] = max(tree[i*2+1], tree[i*2+2]);
        }
    };

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();

        vector<pr> valToInd;
        for(int i=0;i<n;++i){
            valToInd.push_back({nums[i]-i,i}); // (nums[i]-i)
        }

        sort(begin(valToInd),end(valToInd));

        unordered_map<int,int> mp; // mapping index to their new sorted position
        for(int i=0;i<n;++i){ 
            mp[valToInd[i].second]=i;
        }

        SegTree tree(n);

        for(int i=n-1;i>=0;--i){
            int pos=mp[i]; // getting the position of ith index
            ll maxSum=1LL*nums[i]+tree.query(pos+1,n-1); // getting the max val in right of ith index position
            tree.update(pos,maxSum);
        }

        return tree.query(0,n-1); // returning the max across entire score

    }
};