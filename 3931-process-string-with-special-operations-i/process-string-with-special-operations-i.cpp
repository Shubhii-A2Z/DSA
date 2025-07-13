class Solution {
public:
    string processStr(string s) {
        string ans;
        for(int i=0;i<s.length();++i){
            int ch=s[i]-'a';
            if(ch>=0 && ch<=25) ans.push_back(s[i]);
            else if(s[i]=='*'){
                if(ans.length()) ans.pop_back();
            }
            else if(s[i]=='#'){
                string dup=ans;
                ans=ans+dup;
            }
            else reverse(begin(ans),end(ans));
        }
        return ans;
    }
};