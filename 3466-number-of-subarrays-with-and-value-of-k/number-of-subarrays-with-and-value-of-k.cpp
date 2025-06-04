class Solution {
public:
    typedef long long ll;

    // To calculate AND of all numbers in the window:
    // If all numbers in the window have bit i set, then only AND will also have that bit.
    // So, if fq[i] == window size, we include (1 << i) in AND.
    int currAND(vector<int> &fq,int len){
        int ans=0;
        for(int i=0;i<32;++i){
            if(fq[i]==len) ans+=(1<<i);
        }
        return ans;
    }

    ll atLeastK(vector<int> &nums,int k){
        ll cnt=0;
        vector<int> fq(32,0); //storing freq of each bit position
        int l=0,r=0;

        while(r<nums.size()){
            for(int i=0;i<32;++i){
                if(nums[r]&(1<<i)) fq[i]++; //fq[i] counts how many numbers in the current window have the i-th bit set.
            }
            while(r-l+1>0 && currAND(fq,r-l+1)<k){ //Shrink the window from the left (move l forward) until the AND becomes ≥ k again
                for(int i=0;i<32;++i){
                    if(nums[l]&(1<<i)) fq[i]--;
                }
                l++;
            }
            cnt+=(r-l+1); //count all subarrays ending at r and starting from l to r.
            r++;
        }

        return cnt;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        return atLeastK(nums,k)-atLeastK(nums,k+1);
    }
};