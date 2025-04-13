class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()<=2) return s;
        vector<int> freq(26,0);
        for(auto &ch:s) freq[ch-'a']++;

        string left,mid,right;

        int i=0;
        while(i<26){
            char ch=i+'a';
            if(freq[ch-'a']==0){
                i++;
                continue;
            }
            if(freq[ch-'a']&1){ // odd freq
                int half=freq[ch-'a']/2;
                for(int i=1;i<=half;++i){
                    left.push_back(ch);
                    right.push_back(ch);
                }
                mid.push_back(ch);
            }
            else{
                int half=freq[ch-'a']/2;
                for(int i=1;i<=half;++i){
                    left.push_back(ch);
                    right.push_back(ch);
                }
            }
            ++i;
        }

        reverse(begin(right),end(right));
        return left+mid+right;
    }
};