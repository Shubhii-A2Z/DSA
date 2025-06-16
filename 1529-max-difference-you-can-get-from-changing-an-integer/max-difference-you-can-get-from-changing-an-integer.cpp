class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        string s2=s;
        int i=0,j=0;

        //first character not eq to 9
        while(i<s.length() && s[i]=='9') i++;
        //first character not eq to 1 or 0
        while(j<s2.length() && (s2[j]=='1' || s2[j]=='0')) j++;

        char ch1=s[i], ch2=s2[j];
        for(int k=i;k<s.length();++k){
            if(s[k]==ch1) s[k]='9';
        }

        bool flag=(j==0); // if j>0 we can put 0 instead of 1
        for(int k=j;k<s2.length();++k){
            if(s2[k]==ch2){
                s2[k]=flag ? '1' : '0';
            }
        }

        int num1=stoi(s), num2=stoi(s2);
        return num1-num2;
    }
};