class Solution {
public:
    vector<int> buildArray(vector<int>& arr) {
        vector<int> ans(arr.size());;
        for(int i=0;i<ans.size();i++){
            ans[i]=arr[arr[i]];
        }
        return ans;

    }
};