class Solution {
public:
    

    // used for finding(precomputing) prime numbers in range [1,n]
    // Time:O(nloglog(sqrt(n)))
    // Space:O(n)

    // prime sieve
    // n=10 --> 2 3 5 7
    vector<bool> sieve(int n){

        vector<bool> isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i<=sqrt(n);i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        
        return isPrime;
    }

    int primeSubarray(vector<int>& nums, int k) {
        int i=0,j=0;
        multiset<int> st;

        vector<bool> isPrime=sieve(50002);

        int rPrime=-1, srPrime=-1; // recentPrime idx and secondRecentPrime idx

        int cnt=0;
        while(j<nums.size()){
            if(isPrime[nums[j]]){
                st.insert(nums[j]);
                srPrime=rPrime;
                rPrime=j;
            }

            while(i<j && (st.size() && (*st.rbegin()-*st.begin()>k))){
                if(isPrime[nums[i]]) st.erase(st.find(nums[i]));
                i++;
            }

            if(st.size()>=2) cnt+=(srPrime-i+1); // since there should be atleast 2 prime nos, hence the cnt of valid subarrays would be from secondRecentPrime to i (secondRecent---->i------>j)

            j++;
        }

        return cnt;
    }
};