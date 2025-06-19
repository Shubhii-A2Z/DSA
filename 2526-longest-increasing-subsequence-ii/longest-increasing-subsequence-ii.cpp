class Solution {
public:
    #define pr pair<int, int>
    
    struct SegTree {
    public:
    
        SegTree (int _n) : n (_n) {
            tree.resize(4*n, 0);
        }
        
        int query (int x, int y) {
            return query (x, y, 0, n-1, 0);
        }
        
        void update (int ind, int val) {
            update (ind, val, 0, n-1, 0);
        }
    
    private:
        
        vector<int> tree;
        int n;
        
        int query (int x, int y, int l, int r, int i) {
            if (r < x || l > y) return 0;
            if (l >= x && r <= y) return tree[i];
            
            int m = (l+r) >> 1;
            return max(
                query (x, y, l, m, i*2+1),
                query (x, y, m+1, r, i*2+2)
            );
        }
        
        void update (int ind, int val, int l, int r, int i) {
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

    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        SegTree tree(100005);
        
        for(int i=0;i<n;++i){
            int l=max(0,nums[i]-k), r=nums[i]-1;
            int maxLen=1+tree.query(l,r);
            tree.update(nums[i],maxLen);
        }

        return tree.query(0,100005);
    }
};