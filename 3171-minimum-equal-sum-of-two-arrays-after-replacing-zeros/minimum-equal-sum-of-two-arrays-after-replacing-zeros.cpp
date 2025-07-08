class Solution {
public:
    typedef long long ll;
    long long minSum(vector<int>& v1, vector<int>& v2) {
        ll cntZro1=count(begin(v1),end(v1),0), cntZro2=count(begin(v2),end(v2),0);

        ll sum1=accumulate(begin(v1),end(v1),0LL), sum2=accumulate(begin(v2),end(v2),0LL);

        ll minSum1=sum1+cntZro1, minSum2=sum2+cntZro2;
        if(minSum1==minSum2) return minSum1;
        else if(minSum1<minSum2){
            if(cntZro1) return minSum2;
            return -1;
        }
        else{
            if(cntZro2) return minSum1;
            return -1;
        }
        
    }
};