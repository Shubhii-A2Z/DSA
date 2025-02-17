class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> v(26,0);
        for(auto &ch:tiles) v[ch-'A']++;

        // unordered_set<string> st;
        auto dfs=[&](auto &&dfs)->int{
            int ct=0;
            for(int i=0;i<26;++i){
                if(v[i]==0) continue;
                v[i]--;
                ct+=1+dfs(dfs);
                v[i]++;
            }
            return ct;
        };

        return dfs(dfs);
    }
};