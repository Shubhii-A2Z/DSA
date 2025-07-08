class Solution {
public:
    int minProcessingTime(vector<int>& time, vector<int>& tasks) {
       sort(begin(time),end(time));
       sort(begin(tasks),end(tasks),greater<int>());

        vector<int> temp;
        int t=0;
        for(int i=0;i<tasks.size();++i){
            if(t%4==0) temp.push_back(tasks[i]);
            t++;
        }

        int maxe=-1;
        for(int i=0;i<time.size();++i){
            maxe=max(maxe,time[i]+temp[i]);
        }

        return maxe;
    }
};