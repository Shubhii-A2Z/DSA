class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        unordered_map<int,int> inX, outX, inY, outY;

        for(auto &itr:rectangles){
            int x1=itr[0], y1=itr[1], x2=itr[2], y2=itr[3];

            inX[x1]++; outX[x2]++;
            inY[y1]++; outY[y2]++;
        } 

        auto check=[](unordered_map<int,int> &in,unordered_map<int,int> &out)->bool{
            vector<int> pt;

            for(auto &itr:in) pt.push_back(itr.first);
            for(auto &itr:out) pt.push_back(itr.first);

            sort(begin(pt),end(pt));
            pt.erase(unique(pt.begin(),pt.end()),pt.end());

            int currRec=0, cnt=0;
            for(int i=0;i<pt.size();++i){
                currRec-=out[pt[i]];
                if(out[pt[i]] && !currRec){
                    cnt++;
                    if(cnt==2){
                        return i<pt.size()-1;
                    }
                }
                currRec+=in[pt[i]];
            }

            return false;
        };

        return check(inX,outX) || check(inY,outY);
    }
};