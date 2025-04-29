class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe=*max_element(begin(nums),end(nums));
        int maxFq=0;

        int i=0,j=0;
        while(j<nums.size() && maxFq<k){
            maxFq+=nums[j]==maxe; j++;
        }

        ll cnt=0;
        while(j<nums.size()){
            while(i<nums.size() && maxFq>=k){
                maxFq-=nums[i]==maxe;
                i++;
            }
            if(maxFq>=k-1) cnt+=(i);
            maxFq+=nums[j]==maxe;
            j++;
        }

        while(i<nums.size() && maxFq>=k){
            maxFq-=nums[i]==maxe;
            i++;
        }
        if(maxFq>=k-1) cnt+=(i);

        return cnt;
    }
};