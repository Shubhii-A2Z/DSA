class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<colors.length();++i){
            mp[colors[i]].push_back(neededTime[i]);
        }

        for(auto &[c,v]:mp){
            sort(begin(v),end(v));
        }

        int cst=0;
        for(int i=1;i<colors.length();++i){
            if(colors[i]==colors[i-1]){
                vector<int> c;
                c.push_back(neededTime[i-1]);
                char color=colors[i];
                int j=i;
                while(j<colors.length() && colors[j]==color){
                    c.push_back(neededTime[j]);
                    j++;
                }
                sort(begin(c),end(c));
                cst+=accumulate(begin(c),end(c),0)-c.back();
                i=j-1;
            }
        }

        return cst;
    }
};