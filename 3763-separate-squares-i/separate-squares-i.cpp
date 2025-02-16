class Solution {
public:
    typedef long long ll;
    bool isLowerGreater(vector<vector<int>> &sq,double midY){
        double lowerArea=0, upperArea=0;
        for(auto &itr:sq){
            int bottomY=itr[1], side=itr[2], topY=bottomY+side;
            if(topY<midY){
                lowerArea+=(1LL*side*side);
            }
            else if(bottomY>midY){
                upperArea+=(1LL*side*side);
            }
            else{
                double upperSide=topY-midY;
                double lowerSide=midY-bottomY;
                lowerArea+=(lowerSide*side);
                upperArea+=(upperSide*side);
            }
        }
        return lowerArea>=upperArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        auto getMinY=[&]()->double{
            double minVal=1e5;
            for(auto &itr:squares){
                minVal=min(minVal,double(itr[1]));
            }
            return minVal;
        };

        auto getMaxY=[&]()->double{
            double maxVal=0;
            for(auto &itr:squares){
                maxVal=max(maxVal,double(itr[1]+itr[2]));
            }
            return maxVal;
        };

        double minY=getMinY(),maxY=getMaxY();
        double ans=-1;
        double precision=1e-5;

        while(maxY-minY>precision){
            double midY=(minY+maxY)/2.0;
            if(isLowerGreater(squares,midY)){
                ans=midY;
                maxY=midY;
            }
            else minY=midY;
        }

        return ans;
    }
};