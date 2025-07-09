class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
        vector<int> freeGaps(1,start.front());
        for(int i=1;i<start.size();++i){
            freeGaps.push_back(start[i]-end[i-1]); // gap length = (startTime - endTime of previous)
        }
        freeGaps.push_back(eventTime-end.back());

        int maxSum=0, sum=0;
        for(int i=0;i<freeGaps.size();++i){
            sum+=(freeGaps[i]-((i>=k+1) ? freeGaps[i-(k+1)] : 0)); // max gap sum over window of size (k+1)
            maxSum=max(maxSum,sum);
        }

        return maxSum;
    }
};