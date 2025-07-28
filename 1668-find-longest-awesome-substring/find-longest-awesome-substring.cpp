class Solution {
public:
    // exactly same qn as leetcode - 1915

    int longestAwesome(string s) {
        unordered_map<int,int> mp; //{mask,firstSeenIndex}
        int maxLen=1, currMask=0;
        mp[0]=-1;

        for(int i=0;i<s.length();++i){
            char ch=s[i];
            currMask^=(1<<(ch-'0'));

            if(!mp.count(currMask)) mp[currMask]=i; // mark the index at which this mask is seen
            else{
                maxLen=max(maxLen,i-mp[currMask]); // If two prefixes have the same parity mask → the substring between them has all even counts. (assume this as prefix sum, if the sum has appeared before as well, it means the sum of numbers in b/w is 0)
            }

            for(int j=0;j<10;++j){  // If their masks differ by exactly one bit → the substring bw them has exactly one character with an odd count (and rest even).
                int oddMask=currMask^(1<<j);
                if(mp.count(oddMask)) maxLen=max(maxLen,i-mp[oddMask]);
            }

        }

        return maxLen;
    }
};