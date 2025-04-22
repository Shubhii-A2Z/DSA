class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:t) mp[ch]++;
        int l=0,r=0,min_len=1e9,st_idx=-1,cnt=0;
        while(r<s.length()){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==t.length()){
                if(r-l+1<min_len){
                    min_len=r-l+1;
                    st_idx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return st_idx==-1?"":s.substr(st_idx,min_len);
    }
};