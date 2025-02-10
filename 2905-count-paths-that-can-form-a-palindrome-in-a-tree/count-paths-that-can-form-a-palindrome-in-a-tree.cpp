class Solution {
public:
    typedef long long ll;
    unordered_map<int,int> mp; // {mask,freq};
    vector<int> mask; // store mask for each node
    unordered_map<int,vector<pair<int,int>>> graph;

    void dfs(int node,int curr_mask){
        mp[curr_mask]++;
        mask[node]=curr_mask;

        for(auto &nbr:graph[node]){
            int id=nbr.second-'a';
            dfs(nbr.first,curr_mask^(1<<id));
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        mask.resize(n);

        for(int i=1;i<n;++i){
            int u=parent[i], v=i;
            graph[u].push_back({v,s[i]});
        }

        dfs(0,0);
        ll ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<26;++j){ // every 26 results
                int msk=mask[i]^(1<<j);
                ans+=mp[msk];
            }
            ans+=(mp[mask[i]]-1);
        }

        return ans/2; // every pair (u,v) has been counted twice, hence divide by 2
    }
};