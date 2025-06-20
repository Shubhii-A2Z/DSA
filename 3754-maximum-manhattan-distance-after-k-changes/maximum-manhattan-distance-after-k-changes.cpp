class Solution {
public:
    int maxDistance(string s, int k) {
        int maxD=0;
        for(auto hor:{'E','W'}){
            for(auto ver:{'N','S'}){
                // EN, ES, WN, WS
                int x=0,y=0, kRemains=k;
                for(auto ch:s){
                    if(ch==hor && kRemains){
                        ch=((ch=='E') ? 'W' : 'E');
                        kRemains--;
                    }
                    else if(ch==ver && kRemains){
                        ch=((ch=='N') ? 'S' : 'N');
                        kRemains--;
                    }

                    x+=(ch=='E');
                    x-=(ch=='W');
                    y+=(ch=='N');
                    y-=(ch=='S');
                    maxD=max(maxD,abs(x)+abs(y));
                }
            }
        }
        return maxD;
    }
};