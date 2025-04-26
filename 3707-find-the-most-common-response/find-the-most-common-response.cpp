class Solution {
public:
    string findCommonResponse(vector<vector<string>>& r) {
       unordered_map<string,int> mp; 

       for(int i=0;i<r.size();++i){
            unordered_set<string> st;
            for(int j=0;j<r[i].size();++j){
                string s=r[i][j];
                if(!st.count(s)){
                    mp[s]++;
                    st.insert(s);
                }
            }  
       }

       vector<pair<string,int>> v;
       for(auto &[word,fq]:mp) v.push_back({word,fq});

       sort(begin(v),end(v),[&](auto &a,auto &b){
            if(a.second==b.second) return a.first<=b.first;
            return a.second>=b.second;
       });

       return v.front().first;
    }
};