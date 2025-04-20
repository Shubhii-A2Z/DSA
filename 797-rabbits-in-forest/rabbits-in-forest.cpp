class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> mp;
        int result=0;
        for(int i=0;i<ans.size();i++){
            if(mp.find(ans[i]+1)==mp.end()){
                result+=ans[i]+1;
                if(ans[i]==0) continue;
                mp[ans[i]+1]=1;
            }
            else{
                mp[ans[i]+1]++;
                int key=ans[i]+1;
                int val=mp[key];
                if(key==val) mp.erase(key);
            }
        }
        return result;
    }
};