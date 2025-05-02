class Solution {
public:
    string pushDominoes(string d) {
        int n=1e5+3;
        vector<int> v1(d.length(),0), v2(d.length(),0);

        for(int i=0;i<d.length();++i){
            if(d[i]=='R'){
                while(i<d.length() && d[i]=='R') i++;
                int j=i;
                while(j<d.length() && d[j]!='L'){
                    v1[j]=(d[j]=='R' ? 0 : n);
                    if(d[j]=='R') n=1e5+3;
                    else n--;
                    j++;
                }
                n=1e5+3;
                i=j;
            }
        }

        n=1e5+3;
        for(int i=d.length()-1;i>=0;--i){
            if(d[i]=='L'){
                while(i>=0 && d[i]=='L') i--;
                int j=i;
                while(j>=0 && d[j]!='R'){
                    v2[j]=(d[j]=='L' ? 0 : n);
                    if(d[j]=='L') n=1e5+3;
                    else n--;
                    j--;
                }
                n=1e5+3;
                i=j;
            }
        }

        for(int i=0;i<d.length();++i){
            if(v1[i]>v2[i]) d[i]='R';
            else if(v1[i]<v2[i]) d[i]='L';
        }

        return d;
    }
};