class Solution {
public:
    typedef long long ll;
    #define maxLog 31

    int basis[maxLog]{};
    int sze;

    void insertVector(int mask){
        for(int i=maxLog-1;i>=0;--i){
            if(mask&(1<<i)){ // if ith bet of mask is set
                if(!basis[i]){ // if there is no basis with ith bet set, then insert this vector into the basis
                    basis[i]=mask;
                    sze++;
                    return;
                }
                else mask^=basis[i]; // else xor/reduce the mask with the basis vector
            }
        }
    }

    long long maximizeXorAndXor(vector<int>& nums) {
        int n=nums.size();

        ll maxVal=0;
        for(int mask=0;mask<(1<<n)-1;++mask){
            sze=0;
            ll subsetAnd=mask!=0 ? (1<<(maxLog-1))-1 : 0, remainingEleXor=0;
            memset(basis,0,sizeof(basis));

            for(int i=0;i<n;++i){
                if(mask&(1<<i)) subsetAnd&=nums[i];
                else remainingEleXor^=nums[i];
            }

            for(int i=0;i<n;++i){
                if(mask&(1<<i)) continue;
                insertVector(nums[i]&(~remainingEleXor));
            }

            // now finding max value of (xorA+xorB) of remaining indices, using xor basis
            ll maxXor=0;
            for(int i=maxLog-1;i>=0;--i){
                if(!(maxXor&(1<<i)) && basis[i]) maxXor^=basis[i];
            }

            // cout<<subsetAnd<<' '<<maxXor<<' '<<remainingEleXor<<endl;
            maxVal=max(maxVal,subsetAnd+maxXor+(maxXor^remainingEleXor));
        }

        return maxVal;
    }
};