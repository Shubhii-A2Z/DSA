class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        set<int> vis;
        int cnt=0;
        for(int i=0;i<f.size();++i){
            bool flag=false;
            for (int j=0;j<f.size();++j){
                if(!vis.count(j) && b[j]>=f[i]){
                    vis.insert(j);
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                cnt++;
            }
        }
        return cnt;
    }
};