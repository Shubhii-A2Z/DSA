class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3) return 0;
        int cnt=0, len=2;
        int currDiff=v[1]-v[0];
        for(int i=2;i<v.size();++i){
            if(v[i]-v[i-1]==currDiff) len++;
            else{
                if(len==3) cnt++;
                else if(len>3) cnt+=(len-1)*(len-2)/2;
                len=2;
                currDiff=v[i]-v[i-1];
            }
        }
        if(len==3) cnt++;
        else if(len>3) cnt+=(len-1)*(len-2)/2;
        return cnt;
    }
};