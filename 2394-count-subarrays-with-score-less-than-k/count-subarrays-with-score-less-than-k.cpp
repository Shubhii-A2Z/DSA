class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=0) return 0;
        int n=nums.size();
        long long i=0;
        long long j=0;
        long long count=0;
        long long sum=0;
        long long score=0;
        while(j<n){
            sum += (long long)nums[j];
            score=sum*(long long)(j-i+1);
                while(score>=k){
                    count+=(long long)(j-i);
                    sum-=(long long)nums[i];
                    i++;
                    score=(sum)*(long long)(j-i+1);
                }
            j++;
        }
        while(i<n){
            count+=(j-i);
            sum-=(long long)nums[i];
            i++;
        }
        return (long long)count;
    }
};