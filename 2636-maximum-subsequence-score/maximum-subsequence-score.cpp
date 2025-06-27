class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;

        for(int i=0;i<nums1.size();++i){
            v.push_back({nums1[i],nums2[i]});
        }

        sort(begin(v),end(v),[&](auto &a,auto &b){
            return a.second>b.second; // sorting v in descending order
        });

        priority_queue<int,vector<int>,greater<int>> pq;

        ll topKsum=0;

        ll maxScore=INT_MIN;

        for(int i=0;i<v.size();++i){
            int mine=v[i].second; // sice v is descending, hence "v[i].second" is the minimum now
            pq.push(v[i].first);
            topKsum+=v[i].first;

            if(pq.size()>k){ // finding out the top k sum from prefix
                topKsum-=(pq.top()); // removing the least element from topKsum
                pq.pop();
            }
            
            if(pq.size()==k){
                maxScore=max(maxScore,1LL*mine*topKsum);
            }
        }

        return maxScore;
    }
};