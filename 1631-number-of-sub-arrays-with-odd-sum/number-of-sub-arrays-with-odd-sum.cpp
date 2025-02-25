class Solution {
public:
    #define MOD 1000000007
    int numOfSubarrays(vector<int>& arr) {
        int preSum=0, oCnt=0, eCnt=1;
        int cnt=0;

        for(int ele:arr){
            preSum+=ele;
            if(preSum&1){ // preSum is odd
                cnt=(cnt+eCnt)%MOD;
                oCnt++;
            }
            else{ // preSum is even
                cnt=(cnt+oCnt)%MOD;
                eCnt++;
            }
            cout<<cnt<<endl;
        }

        return cnt;
    }
};