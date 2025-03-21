class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        multimap<int,int> mp;
        for(int i=0;i<d.size();++i){
            mp.insert({d[i],p[i]});
        }

        vector<int> maxProf;
        int maxe=0;

        for(auto &[d,p]:mp){
            maxe=max(maxe,p);
            // cout<<maxe<<" ";
            maxProf.push_back(maxe);
        }

        sort(begin(d),end(d));
        int tProfit=0;

        for(int i=0;i<w.size();++i){
            int idx=upper_bound(begin(d),end(d),w[i])-begin(d);
            if(idx==0) continue;
            // cout<<maxProf[idx-1]<<endl;
            tProfit+=maxProf[idx-1];
        }

        return tProfit;
    }
};