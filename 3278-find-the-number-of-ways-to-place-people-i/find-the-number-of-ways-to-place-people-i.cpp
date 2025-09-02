class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points),end(points),[&](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        set<pair<int,int>> s;
        for(auto &p:points){
            s.insert({p[0],p[1]});
        }

        int cnt=0;
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                if(y1<y2) continue;

                s.erase({x1,y1}); s.erase({x2,y2});
                bool flag=false;
                for(auto &[x,y]:s){
                    if((x>=x1 && x<=x2) && (y>=y2 && y<=y1)){
                        flag=true;
                        break;
                    }
                }
                s.insert({x1,y1}); s.insert({x2,y2});

                if(flag) continue;
                cnt++;
            }
        }

        return cnt;
    }
};