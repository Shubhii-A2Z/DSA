class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        int n=c.size();
        c.insert(end(c),begin(c),end(c));
        int i=0,j=1;
        int cnt=0;
        while(i<n){
            // cout<<i<<" "<<j<<endl;
            if(c[j-1]!=c[j]){
                j++;
            }
            else{
                i=j;
                j++;
            }
            if(j-i==k){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};