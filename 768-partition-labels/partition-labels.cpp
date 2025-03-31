class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,vector<int>> mp; //{char,index}
        for(int i=0;i<s.length();++i){
            mp[s[i]].push_back(i);
        }

        vector<int> ans;

        int maxId=0;
        int prevSum=0;
        for(int i=0;i<s.length();++i){
            if(i>maxId){
                if(!ans.size()) ans.push_back(maxId+1);
                else ans.push_back(maxId+1-prevSum);
                prevSum+=ans.back();
            }
            char ch=s[i];
            int lastIdx=mp[ch].back();
            // cout<<ch<<" "<<lastIdx<<endl;
            maxId=max(maxId,lastIdx);
        }

        if(!ans.size()) ans.push_back(maxId+1);
        else ans.push_back(maxId+1-prevSum);

        return ans;
    }
};