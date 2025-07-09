class GCDSparseTable{
private:
    vector<vector<int>> st; // sparse table to store values
    vector<int> logVal;
    int n;

public:
    GCDSparseTable(const vector<int> &a){
        n=a.size();
        int maxLog=32-__builtin_clz(n);
        st.assign(n,vector<int>(maxLog));
        logVal.assign(n+1,0);

        for(int i=2;i<=n;++i){ // storing in the logValues
            logVal[i]=logVal[i/2]+1;
        }

        for(int i=0;i<n;++i){ // building the first column of sparse table
            st[i][0]=a[i];
        }

        for(int j=1;(1<<j)<=n;++j){ // (2^j) length
            for(int i=0;i+(1<<j)<=n;++i){ // starting index
                st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }

    int getGCD(int l,int r){
        int j=logVal[r-l+1]; // largest power of 2 that fits in (r-l+1)
        return __gcd(st[l][j],st[r-(1<<j)+1][j]);
    }
};

class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
        int cntOnes=count(begin(nums),end(nums),1);
        if(cntOnes+maxC>=nums.size()) return 0;

        GCDSparseTable st(nums); // building a "gcd sparse table" over the array nums

        auto canBreak=[&](int maxLen)->bool{
            int changes=0;
            int l=0,r=0;
            while(r<nums.size()){
                int gcd=st.getGCD(l,r);

                while(gcd==1 && l<r){
                    l++;
                    gcd=st.getGCD(l,r);
                }

                if(r-l+1>maxLen){
                    changes++;
                    l=r+1;
                }
                r++;
            }

            return changes<=maxC;
        };

        int lo=0, hi=nums.size(), ans=-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(canBreak(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;

    }
};