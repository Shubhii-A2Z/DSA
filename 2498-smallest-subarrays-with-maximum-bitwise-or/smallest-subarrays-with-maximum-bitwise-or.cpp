class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // For each bit position, find the position of the next number that has a 1 in that position, if any.
        // Keep taking the maximum distance to such a number, including the current number.
        // TC : O(31*n)
        int n=nums.size();

        vector<int> setPos(31);
        vector<int> ans(n);

        for(int i=n-1;i>=0;--i){
            for(int pos=0;pos<31;++pos){
                if(nums[i]&(1<<pos)){ // if curr bit (pos) is set, store its index in setPos vector
                    setPos[pos]=i;
                }
            } 
            int maxe=*max_element(begin(setPos),end(setPos)); // finding the max index position
            ans[i]=max(maxe,i)-i+1; // length would be max index - current index + 1 (since we're traversing from end)
        }
        return ans;
    }
};