class Solution {
public:
    int dist(int i,int j,int len){
        int dist1=abs(j-i), dist2=len-dist1;
        return min(dist1,dist2);
    }

    int findRotateSteps(string ring, string key) {
        int n=ring.length(), m=key.length();
        vector<int> currDp(n+1,0), nextDp(n+1,0);

        for(int keyIdx=m-1;keyIdx>=0;--keyIdx){
            for(int ringIdx=0;ringIdx<n;++ringIdx){
                int minSteps=INT_MAX;

                for(int i=0;i<n;++i){
                    if(ring[i]==key[keyIdx]){
                        int totalSteps=dist(ringIdx,i,n)+1+nextDp[i];
                        minSteps=min(minSteps,totalSteps);
                    }
                }
                currDp[ringIdx]=minSteps;

            }
            nextDp=currDp;
        }

        return currDp[0];
    }
};