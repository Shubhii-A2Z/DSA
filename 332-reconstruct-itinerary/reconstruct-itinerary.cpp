class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> gr;
        for(auto &t:tickets){
            string u=t[0], v=t[1];
            gr[u].insert(v);
        }

        vector<string> v;

        // v.push_back("JFK");

        auto dfs=[&](auto &&dfs,string currNode)->void{
            while(gr[currNode].size()){
                auto it=gr[currNode].begin();
                string nbr=*it;
                gr[currNode].erase(it);
                dfs(dfs,nbr);
            }
            v.push_back(currNode);
        };

        
        dfs(dfs,"JFK");
        reverse(begin(v),end(v));

        return v;
    }
};