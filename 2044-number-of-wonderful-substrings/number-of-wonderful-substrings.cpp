class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<int,ll> mp;
        mp[0]=1;
        ll cnt=0, currMask=0;
        
        for(int i=0;i<word.length();++i){
            char ch=word[i];

            currMask^=(1<<(ch-'a'));
            cnt+=(mp[currMask]); // If two prefixes have the same parity mask → the substring between them has all even counts. (assume this as prefix sum, if the sum has appeared before as well, it means the sum of numbers in b/w is 0)

            for(int j=0;j<10;++j){ // first 10 characters
                int oddMask=currMask^(1<<j);
                cnt+=(mp[oddMask]); // If their masks differ by exactly one bit → the substring bw them has exactly one character with an odd count (and rest even).
            }

            mp[currMask]++; // storing the current prefixMask
        }

        return cnt;
    }
};