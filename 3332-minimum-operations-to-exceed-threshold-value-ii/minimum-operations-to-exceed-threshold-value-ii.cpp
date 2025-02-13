class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq(begin(nums),end(nums));

        int c=0;
        while(pq.size()>1){
            long long x=pq.top(); pq.pop();
            if(x>=k) break;
            long long y=pq.top(); pq.pop();
            pq.push(2*min(x,y)+max(x,y));
            c++;
        }

        return c;
    }
};