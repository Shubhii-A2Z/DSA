class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& nums, int x, vector<int>& queries) {
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> ind;

        for(int i=0;i<queries.size();++i){
            ind[queries[i]].push_back(i);
        }

        sort(begin(nums),end(nums),[&](auto &a,auto &b){
            return a[1]<b[1];
        });
        sort(begin(queries),end(queries));

        vector<int> ans(queries.size());

        int i=0,j=0;
        for(auto &q:queries){
            int lo=q-x, hi=q;
            while(j<nums.size() && nums[j][1]<=hi){
                mp[nums[j][0]]++;
                j++;
            }

            while(i<nums.size() && nums[i][1]<lo){
                mp[nums[i][0]]--;
                if(!mp[nums[i][0]]) mp.erase(nums[i][0]);
                i++;
            }

            // cout<<mp.size()<<' ';
            for(auto &indices:ind[q]){
                ans[indices]=n-mp.size();
            }
        }

        return ans;
    }
};