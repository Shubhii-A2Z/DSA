class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp=nums;

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]=i;
        }

        auto f=[&](int v)->long long{
            long long sum=0;
            while(v>0){
                sum+=(v%10);
                v/=10;
            }
            return sum;
        };

        sort(begin(nums),end(nums),[&](int a,int b){
            if(f(a)==f(b)) return a<b;
            return f(a)<f(b);
        });

        int cnt=0;
        for(int i=0;i<nums.size();++i){
            // cout<<nums[i]<<" ";
            if(mp[nums[i]]==i) continue;
            else if(mp[nums[i]]>i){
                cnt++;
                mp[temp[i]]=mp[nums[i]];
                // mp[nums[i]]=i;
                swap(temp[i],temp[mp[nums[i]]]);
            }
        }

        return cnt;
    }
};