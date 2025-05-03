class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();

        vector<int> forTop(7,0), forBottom(7,0);
        vector<int> fq(7,0);

        for(int i=0;i<n;++i){
            forTop[t[i]]++;
            forBottom[b[i]]++;
            fq[t[i]]++; 
            if(t[i]!=b[i]) fq[b[i]]++;
        } 

        if(*max_element(begin(fq),end(fq))<n) return -1;

        int mine=n;
        for(int i=0;i<n;++i){
            int req1=n-forTop[t[i]], req2=n-forBottom[b[i]];
            mine=min({mine,req1>=0 ? req1 : n,req2>=0 ? req2 : n});
        }

        return mine;
    }
};