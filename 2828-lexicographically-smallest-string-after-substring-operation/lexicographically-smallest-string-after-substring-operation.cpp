class Solution {
public:
    string smallestString(string s) {
        int i=0;
        while(i<s.length() && s[i]=='a') i++;

        if(i==s.length()){
            s.back()='z';
            return s;
        }

        while(i<s.length() && s[i]!='a'){
            char ch=s[i]-'a'-1;
            s[i]=ch+'a';
            i++;
        }

        return s;
    }
};