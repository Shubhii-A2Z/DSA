class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(begin(m),end(m));
        int nxtDay=1, cnt=0;
        for(int i=0;i<m.size();++i){
            if(m[i][0]>nxtDay){
                cnt+=(m[i][0]-nxtDay);
            }
            nxtDay=max(nxtDay,m[i][1]+1);
        }
        if(days>=nxtDay) cnt+=(days-nxtDay+1);
        return cnt;
    }
};