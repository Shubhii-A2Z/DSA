class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int tCount=0,prevCount=0;
        for(auto &st:bank){
            int cntOne=0;
            for(auto &ch:st) cntOne+=(ch=='1');
            if(cntOne){
                tCount+=(prevCount*cntOne);
                prevCount=cntOne;
            }
        }
        return tCount;
    }
};