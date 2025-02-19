class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> s;
    
        auto dfs=[&](auto &&dfs,int idx,char prev,string str){
            if(idx>=n){
                s.push_back(str);
                return;
            }
            for(int i=0;i<3;++i){
                char ch='a'+i;
                if(ch==prev) continue;
                str.push_back(ch);
                dfs(dfs,idx+1,ch,str);
                str.pop_back();
            }
        };
        dfs(dfs,0,'0',"");

        sort(begin(s),end(s));
        return s.size()<k ? "" : s[k-1];

    }
};