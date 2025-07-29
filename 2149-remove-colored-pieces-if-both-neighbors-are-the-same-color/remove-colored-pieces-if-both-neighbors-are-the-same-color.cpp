class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length()<=2) return false;

        // just find the length of longest consecutive substring of 'A' and 'B'

        int currLenofA=0, currLenOfB=0;
        int maxRemovalsOfA=0, maxRemovalsOfB=0;

        for(int i=0;i<colors.length();++i){
            if(colors[i]=='A'){
                currLenofA++;
                if(currLenOfB>2) maxRemovalsOfB+=(currLenOfB-2);
                currLenOfB=0;
            }
            else{
                currLenOfB++;
                if(currLenofA>2) maxRemovalsOfA+=(currLenofA-2);
                currLenofA=0;
            }
        }

        if(currLenOfB>2) maxRemovalsOfB+=(currLenOfB-2);
        if(currLenofA>2) maxRemovalsOfA+=(currLenofA-2);

        return maxRemovalsOfA>maxRemovalsOfB;
    }
};