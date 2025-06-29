class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> vis;
        vector<string> ans;

        for(int i=0;i<s.length();++i){
            string temp;
            temp.push_back(s[i]);

            int j=i+1;
            while(j<s.length() && vis.count(temp)){
                temp.push_back(s[j]);
                j++;
            }
            if(!vis.count(temp)) ans.push_back(temp);
            vis.insert(temp);
            i=j-1;
        }

        return ans;
    }
};