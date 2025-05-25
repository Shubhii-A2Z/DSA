class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto &c:words) mp[c]++;

        int len=0, cnt=0;
        for(auto &c:words){
            if(!mp.count(c)) continue;
            string rev=c;
            reverse(begin(rev),end(rev));
            if(rev!=c){
                if(!mp.count(rev)) continue;
                len+=4;
                mp[c]--;
                mp[rev]--;
                if(mp[c]==0) mp.erase(c);
                if(mp[rev]==0) mp.erase(rev);
            }
            else{
                if(mp[c]>1){
                    len+=4;
                    mp[c]-=2;
                    if(mp[c]==0) mp.erase(c);
                }
                else if(cnt<1){
                    len+=2;
                    cnt++;
                }
            }
        }

        return len;
    }
};