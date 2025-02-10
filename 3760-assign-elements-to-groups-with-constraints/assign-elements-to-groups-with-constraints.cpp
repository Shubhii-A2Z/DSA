class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        unordered_map<int,int> mp;
        for(int i=0;i<e.size();++i){
            if(!mp.count(e[i])) mp[e[i]]=i;
        }

        vector<int> ans;
        for(int i=0;i<g.size();++i){
            int ele=g[i], minIdx=1e8;
            for(int f=1;f<=sqrt(ele);++f){
                if(ele%f==0){
                    // cout<<f<<" "<<mp[f]<<endl;
                    if(mp.count(f)) minIdx=min(minIdx,mp[f]);
                    if(f!=ele/f && mp.count(ele/f)) minIdx=min(minIdx,mp[ele/f]);
                }
            }
            ans.push_back(minIdx==1e8 ? -1 : minIdx);
        }

        return ans;
    }
};