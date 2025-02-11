class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        for(char ch:s){
            ans.push_back(ch);
            if(ans.length()>=part.length() && ans.substr(ans.length()-part.length())==part){
                int x=part.length();
                while(x--) ans.pop_back();
            }
        }
        return ans;
    }
};