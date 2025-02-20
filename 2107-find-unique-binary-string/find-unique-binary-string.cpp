class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string> s;
        for(auto x:nums) s.insert(x);

        string res;
        auto dfs=[&](auto &&dfs,int idx,string str)->void{
            if(idx>=n){
                if(s.count(str)==0) res=str;
                return;
            }
            for(auto ch:{'0','1'}){
                str.push_back(ch);
                dfs(dfs,idx+1,str);
                str.pop_back();
            }
            if(res.size()) return;
        };

        dfs(dfs,0,"");
        return res;
    }
};