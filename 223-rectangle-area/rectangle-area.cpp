class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len1=max(ax1,bx1), len2=min(ax2,bx2);
        int bdth1=max(ay1,by1), bdth2=min(ay2,by2);

        int commonArea=max(0,len2-len1)*max(0,bdth2-bdth1);
        return (abs(ax2-ax1)*abs(ay2-ay1))+(abs(bx2-bx1)*abs(by2-by1))-commonArea;
    }
};