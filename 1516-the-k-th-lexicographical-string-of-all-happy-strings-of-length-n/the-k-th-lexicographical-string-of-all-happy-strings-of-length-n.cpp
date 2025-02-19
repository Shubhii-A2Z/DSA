class Solution {
public:
    string getHappyString(int n, int k) {
        int cnt=0;
        string res;
        auto dfs=[&](auto &&dfs,int idx,char prev,string str){
            if(idx>=n){
                cnt++;
                if(cnt==k) res=str;
                return;
            }
            for(auto ch:{'a','b','c'}){
                if(ch==prev) continue;
                str.push_back(ch);
                dfs(dfs,idx+1,ch,str);
                str.pop_back();
            }
        };
        dfs(dfs,0,'0',"");

        // sort(begin(s),end(s));
        return res;

    }
};