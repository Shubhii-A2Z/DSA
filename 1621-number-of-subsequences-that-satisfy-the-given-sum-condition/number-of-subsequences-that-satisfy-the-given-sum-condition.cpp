class Solution {
public:
    #define MOD 1000000007
    int expo(int base, int exp, int mod=MOD) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2) res = (res * base) % mod;
            base = (1LL * base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums)); 

        int cnt=0;
        for(int i=0;i<nums.size();++i){
            int ele=nums[i];
            if(ele>target) break;
            int idx=upper_bound(begin(nums)+i,end(nums),target-ele)-begin(nums);
            idx--;
            if(idx<i) continue;
            else cnt=(cnt+expo(2,idx-i))%MOD;
        }

        return cnt;
    }
};