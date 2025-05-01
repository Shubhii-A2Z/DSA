class Solution {
public:
    string shortestPalindrome(string s) {
        //using kmp algorithm
        string t=s,ans=s;
        reverse(t.begin(),t.end());
        int len=s.length();
        s.push_back('.');
        s+=t;
        vector<int> lps(s.length(),0);
        int pre=0,suff=1;

        while(suff<s.length()){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0) suff++;
                else pre=lps[pre-1];
            }
        }
        int idx=lps[s.length()-1];
        string palind="";
        for(int i=idx;i<len;i++){
            palind+=ans[i];
        }
        reverse(palind.begin(),palind.end());
        palind+=ans;
        return palind;

    }
};