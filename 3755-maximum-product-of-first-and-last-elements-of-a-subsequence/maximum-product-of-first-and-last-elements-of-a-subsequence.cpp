class Solution {
public:
    typedef long long ll;
    long long maximumProduct(vector<int>& nums, int m) {
        multiset<ll> s(begin(nums),end(nums));

        for(int i=0;i<m-1;++i){
            int currEle=nums[i];
            s.erase(s.find(currEle));
        }

        ll maxProd=LLONG_MIN;

        for(int i=0;i<nums.size()-m+1;++i){
            ll maxEle=*s.rbegin(), minEle=*s.begin();
            // if(nums[i]==0) continue;

            if(nums[i]>0) maxProd=max(maxProd,maxEle*nums[i]);
            else maxProd=max(maxProd,minEle*nums[i]); 

            s.erase(s.find(nums[i+m-1]));
        }

        return maxProd;
    }
};