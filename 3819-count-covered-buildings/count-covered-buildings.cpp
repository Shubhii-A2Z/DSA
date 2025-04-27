class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int countCoveredBuildings(int n, vector<vector<int>>& b) {

        sort(begin(b),end(b),[&](auto &p1,auto &p2){
            if(p1[0]==p2[0]) return p1[1]<=p2[1];
            return p1[0]<=p2[0];
        });

        unordered_map<int,vector<int>> mp1; //{row,y coord of pts}
        unordered_map<int,vector<int>> mp2; //{col,x coord of pts}
        
        
        for(auto &it:b){
            int i=it[0], j=it[1];
            mp1[i].push_back(j);
            mp2[j].push_back(i);
        }

        int cnt=0;
        for(auto &it:b){
            int i=it[0], j=it[1];
            auto &v1=mp1[i], &v2=mp2[j];
            if(v1.size()==1 || v2.size()==1) continue;
            int idx1=lower_bound(begin(v1),end(v1),j)-begin(v1);
            int idx2=lower_bound(begin(v2),end(v2),i)-begin(v2);
            if(idx1==0 || idx1==v1.size()-1) continue;
            if(idx2==0 || idx2==v2.size()-1) continue;
            cnt++;
        }

        return cnt;
    }
};