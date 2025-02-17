class Solution {
public:
    // TC:O(n+m)
    // Space:O(n+m)
    // To know the actual index actual idx in original string --->
    //                   idx=i-2*(pattern.length())
    vector<int> kmp(const string &s){

        vector<int> lps(s.length());
        for(int i=1;i<lps.size();i++){
            int prev_idx=lps[i-1];
            while(prev_idx>0 && s[i]!=s[prev_idx]){
                prev_idx=lps[prev_idx-1];
            }
            lps[i]=prev_idx+(s[i]==s[prev_idx]);
        }
        return lps;

    }

    int shortestMatchingSubstring(string text, string pattern) {
        int textLen=text.length();
        int patternLen=pattern.length();
        if(patternLen==2) return 0;

        vector<int> starPosition;
        for(int i=0;i<patternLen;++i){
            if(pattern[i]=='*') starPosition.push_back(i);
        }

        string prefix=pattern.substr(0,starPosition[0]);
        string middle=pattern.substr(starPosition[0]+1,starPosition[1]-starPosition[0]-1);
        string suffix=pattern.substr(starPosition[1]+1);
        // cout<<prefix<<" "<<middle<<" "<<suffix;

        int prefixLen=prefix.length(), middleLen=middle.length(), suffixLen=suffix.length();

        vector<int> prefixLps=kmp(prefix+'#'+text);
        vector<int> middleLps=kmp(middle+'#'+text);
        vector<int> suffixLps=kmp(suffix+'#'+text);

        prefixLps=vector<int>(begin(prefixLps)+prefixLen+1,end(prefixLps));
        middleLps=vector<int>(begin(middleLps)+middleLen+1,end(middleLps));
        suffixLps=vector<int>(begin(suffixLps)+suffixLen+1,end(suffixLps));

        int i=0,j=0,k=0;
        int minLen=INT_MAX;

        while(i+middleLen+suffixLen<textLen){
            while(i<textLen && prefixLps[i]!=prefixLen) i++;
            if(i>=textLen) break;

            // j=i+middleLen;
            while(j<textLen && (j<i+middleLen || middleLps[j]!=middleLen)) j++;
            if(j>=textLen) break;

            // k=j+suffixLen;
            while(k<textLen && (k<j+suffixLen || suffixLps[k]!=suffixLen)) k++;
            if(k>=textLen) break;

            minLen=min(minLen,k-i+prefixLen);
            i++;
        }

        return minLen==INT_MAX ? -1 : minLen; 
    }
};