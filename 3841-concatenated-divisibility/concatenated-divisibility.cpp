class Solution {
public:
    int dp[(1<<15)+10][101];
    bool check(int mask,int rem,vector<int> &nums,int k){
        if(mask==(1<<nums.size())-1){
            return rem==0;
        }

        int &res=dp[mask][rem];
        if(res!=-1) return res;

        bool ans=false;
        for(int i=0;i<nums.size();++i){
            if(mask&(1<<i)) continue; // ith element is already taken
            else{
                int num=nums[i], mul=1;
                while(num>0){
                    mul*=10;
                    num/=10;
                }
                ans|=check(mask|(1<<i),((1LL*rem*mul)+nums[i])%k,nums,k);
            }
        }

        return res=ans;
    }

    vector<int> v;
    void f(int id,int mask,int rem,vector<int> &nums,int k){
        if(mask==(1<<nums.size())-1) return;

        int newMask=mask, newRem=rem;
        for(int i=0;i<nums.size();++i){
            if(mask&(1<<i)) continue; // ith element is already taken
            else{
                int num=nums[i], mul=1;
                while(num>0){
                    mul*=10;
                    num/=10;
                }
                bool ans=check(mask|(1<<i),((1LL*rem*mul)+nums[i])%k,nums,k);

                if(ans && v[id]>nums[i]){ // we found a lesser answer
                    newMask=mask|(1<<i);
                    newRem=((1LL*rem*mul)+nums[i])%k;
                    v[id]=nums[i];
                }
            }
        }

        f(id+1,newMask,newRem,nums,k);
    }

    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        bool flag=check(0,0,nums,k);
        if(!flag) return {}; // there's no valid answer

        v.resize(nums.size(),INT_MAX);
        f(0,0,0,nums,k);
        return v;
    }

};