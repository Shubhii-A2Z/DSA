class Solution {
public:
    #define typedef long long ll;
 
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
            return (
                query (x, y, l, m, i*2+1) +
                query (x, y, m+1, r, i*2+2)
            );
        }
        
        void update (int ind, int val, int l, int r, int i) {
            if (l == r) {
                tree[i] += val;
                return;
            }
            
            int m = (l+r) >> 1;
            if (m >= ind) update (ind, val, l, m, i*2+1);
            else update (ind, val, m+1, r, i*2+2);
            
            tree[i] = tree[i*2+1] + tree[i*2+2];
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        set<int> s(begin(nums1),end(nums1));
        unordered_map<int,int> mp1; // maps element and their pos of nums1
        
        int idx=0;
        unordered_map<int,int> mp;
        for(auto &e:s){ // mapping elements to their correct indices
            mp[e]=idx;
            idx++;
        }

        for(int i=0;i<n;++i){
            mp1.insert({nums1[i],i});
        }  
        for(auto &ele:nums2){
            ele=mp1[ele];
        }   
        
        SegTree tree1(n), tree2(n);
        vector<int> v1(n), v2(n);

        for(int i=0;i<n;++i){ // filling v1 array i.e. count of elements smaller on left
            int ele=nums2[i], pos=mp[ele];
            v1[i]=(tree1.query(0,pos-1));
            tree1.update(pos,1);
        }

        for(int i=n-1;i>=0;--i){ // filling v2 array i.e. count of elements larger on right
            int ele=nums2[i], pos=mp[ele];
            v2[i]=(tree2.query(pos+1,n-1));
            tree2.update(pos,1);
        }

        long long cnt=0;
        for(int y=0;y<n;++y){ // now finding for every value y
            cnt+=(1LL*v1[y]*v2[y]);
        }

        return cnt;
    }
};