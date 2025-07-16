class Solution {
public:
    int dp[200002][3][3];
    int f(int i,int prevParity,int prevEParity,vector<int> &nums){
        if(i>=nums.size()){
            return 0;
        }

        int &ans=dp[i][prevParity][prevEParity];
        if(ans!=-1) return ans;

        int notTake=f(i+1,prevParity,prevEParity,nums);
        int take=0;

        int currE=nums[i];
        bool currEParity=currE&1; //0-even parity, 1-odd parity

        if(prevParity==0){ // this is either first or second ele of our subsequence
            if(prevEParity==0){ // this is the first element
                take=1+f(i+1,prevParity,currEParity ? 1 : 2,nums);
            }
            else{ // this is our sec element
                if((prevEParity==1 && currEParity) || (prevEParity==2 && !currEParity)){
                    take=1+f(i+1,2,currEParity ? 1 : 2,nums);
                }
                else take=1+f(i+1,1,currEParity ? 1 : 2,nums);
            }
        }
        else{
            if(prevParity==1){ // prevParity of sum of elements is odd, hence current sum parity should also be odd
                if(!((prevEParity==1 && currEParity) || (prevEParity==2 && !currEParity))){ // both curr and prev element should be of opp parity
                    take=1+f(i+1,prevParity,currEParity ? 1 : 2,nums);
                }
            }
            else{ // prevParity of sum of elements is even, hence current sum parity should also be even
                if((prevEParity==1 && currEParity) || (prevEParity==2 && !currEParity)){ // both curr and prev element should be of same parity
                    take=1+f(i+1,2,currEParity ? 1 : 2,nums);
                }
            }
        }

        return ans=max(take,notTake);
    }

    int maximumLength(vector<int>& nums) {
        if(nums.size()==2) return 2;

        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,0,nums);

        return ans<=2 ? 2 : ans;
    }
};