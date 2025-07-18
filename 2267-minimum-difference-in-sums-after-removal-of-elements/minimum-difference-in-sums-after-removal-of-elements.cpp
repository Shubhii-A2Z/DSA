class Solution {
public:
    typedef long long ll;
    long long minimumDifference(vector<int>& nums) {
        int len=nums.size()/3;
        // our aim is to remove the largest element from first part, and smallest element from second part -> this would minimize the difference

        // Step 1: Find the min sum of 'n' elements till idx i
        priority_queue<int> pq;
        unordered_map<int,ll> mp;

        ll minSum=0;
        for(int i=0;i<nums.size()-len;++i){
            pq.push(nums[i]);
            minSum+=nums[i];
            if(pq.size()>len){
                minSum-=(pq.top());
                pq.pop();
            }
            if(pq.size()==len) mp[i]=minSum; // storing the minSum of len elements uptil ith idx
        }

        ll minDiff=LLONG_MAX;

        // Step 2: Find the max sum of 'n' elements after idx i
        priority_queue<int,vector<int>,greater<int>> pq2;

        ll maxSum=0;
        for(int i=nums.size()-1;i>=len;--i){
            pq2.push(nums[i]);
            maxSum+=nums[i];
            if(pq2.size()>len){
                maxSum-=(pq2.top());
                pq2.pop();
            }
            if(pq2.size()==len){
                // cout<<mp[i-1]<<' '<<maxSum<<endl;
                minDiff=min(minDiff,mp[i-1]-maxSum); // diff bw minSum of len elements uptil (i-1)th idx and maxSum after ith idx
            }
        }


        return minDiff;
    }
};