class Solution {
public:
    typedef long long ll;
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        ll res=0;
        unordered_set<int> vis;
        for(int i=0;i<values.size();){
            if(vis.count(i)) break;
            vis.insert(i);
            if(instructions[i]=="add"){
                res+=values[i];
                i++;
            }
            else{ // jump
                i+=values[i];
                if(i<0 || i>=values.size()) break;
            }
        }
        return res;
    }
};