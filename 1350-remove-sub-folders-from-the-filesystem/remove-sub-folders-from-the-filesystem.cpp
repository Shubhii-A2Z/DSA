class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        unordered_set<string> st;

        auto isPrefix=[&](string &a,string &b)->bool{
            if(a==b) return false;
            int i=0;
            for(;i<a.length();++i){
                if(a[i]!=b[i]) return false;
            }
            if(b[i]=='/') return true;
            return false;
        };

        for(int i=0;i<folder.size();++i){
            string currSt=folder[i];
            if(st.count(currSt)) continue;
            for(int j=i+1;j<folder.size();++j){
                if(!isPrefix(currSt,folder[j])) break;
                st.insert(folder[j]);
            }
        }

        vector<string> ans;
        for(auto &s:folder){
            if(!st.count(s)) ans.push_back(s);
        }

        return ans;
    }
};