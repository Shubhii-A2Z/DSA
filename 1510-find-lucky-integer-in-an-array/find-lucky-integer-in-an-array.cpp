class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> v(501,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        for(int i=500;i>=1;i--){
            if(i==v[i]) return i;
        }
        return -1;
    }
};