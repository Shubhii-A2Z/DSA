class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
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