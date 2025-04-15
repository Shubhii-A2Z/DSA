class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {

        unordered_map<string,vector<string>> mp;

        vector<string> ans;

        for(auto &itr:a){
            string ch=itr[0], time=itr[1];
            mp[ch].push_back(time);
        }

        for(auto &[ch,v]:mp){
            if(v.size()<3) continue;
            sort(begin(v),end(v),[&](auto &p1,auto &p2){
                return p1<=p2;
            }); 
            
            int i=2;
            while(i<v.size()){
                string time1=v[i-2], time2=v[i];
                int hr1=stoi(time1.substr(0,2)), hr2=stoi(time2.substr(0,2));
                int min1=stoi(time1.substr(2)), min2=stoi(time2.substr(2));
                // cout<<ch<<" "<<hr1<<" "<<hr2<<endl;
                if(hr1==hr2 || hr2-hr1<1 || (hr2-hr1==1 && min2-min1<0)){
                    ans.push_back(ch);
                    break;
                }
                i++;
            }
        }

        return ans;
    }
};