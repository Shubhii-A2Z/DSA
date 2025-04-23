class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        sort(begin(e),end(e)); 

        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0, cnt=0;

        for(int d=0;d<=100000;++d){
            while(pq.size() && pq.top()<d) pq.pop();
            while(i<e.size() && e[i][0]==d){
                pq.push(e[i][1]);
                i++;
            }
            if(pq.size()){
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};