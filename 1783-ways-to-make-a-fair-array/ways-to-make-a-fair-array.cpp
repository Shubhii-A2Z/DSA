class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> oddSum(nums.size(),0), evenSum(nums.size(),0);

        for(int i=0;i<nums.size();++i){
            if(i&1){
                oddSum[i]=i>0 ? oddSum[i-1]+nums[i] : nums[i];
                evenSum[i]=i>0 ? evenSum[i-1] : 0;
            }
            else{
                evenSum[i]=i>0 ? evenSum[i-1]+nums[i] : nums[i];
                oddSum[i]=i>0 ? oddSum[i-1] : 0;
            }
        }

        int cnt=0;
        for(int i=0;i<nums.size();++i){
            if(i&1){ // odd index is being removed
                int prevEvenSum=i>0 ? evenSum[i-1] : 0; // all even indices sum uptil this idx
                int prevOddSum=i>0 ? oddSum[i-1] : 0; // all odd indices sum uptil this idx
                //all the indices after this 'i' will change their parity since 'i' is being removed


                int oddSumNow=i<nums.size()-1 ? oddSum.back()-nums[i]-prevOddSum+prevEvenSum : prevOddSum; // since odd indices have now become even
                int evenSumNow=i<nums.size()-1 ? evenSum.back()-prevEvenSum+prevOddSum : prevEvenSum; // since even indices have now become odd
                cout<<evenSumNow<<' '<<oddSumNow<<endl;
                cnt+=(oddSumNow==evenSumNow);
            }
            else { //even index is being removed
                int prevEvenSum=i>0 ? evenSum[i-1] : 0; // all even indices sum uptil this idx
                int prevOddSum=i>0 ? oddSum[i-1] : 0; // all odd indices sum uptil this idx

                //all the indices after this 'i' will change their parity since 'i' is being removed

                int evenSumNow=i<nums.size()-1 ? evenSum.back()-nums[i]-prevEvenSum+prevOddSum : prevEvenSum; // since even indices have now become odd
                int oddSumNow=i<nums.size()-1 ? oddSum.back()-prevOddSum+prevEvenSum : prevOddSum; // since odd indices have now become even
                cout<<evenSumNow<<' '<<oddSumNow<<endl;
                cnt+=(oddSumNow==evenSumNow);
            }
        }

        return cnt;
    }
};