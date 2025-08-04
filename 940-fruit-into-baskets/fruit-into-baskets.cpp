class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,max_len=0;
        unordered_map<int,int>mp; //{num,freq}
        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2){
                max_len=max(max_len,r-l+1);
            }
            r++;
        }
        return max_len;
    }
};