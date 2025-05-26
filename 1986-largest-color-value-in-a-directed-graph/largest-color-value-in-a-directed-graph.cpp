class Solution {
public:
    #define pb push_back
    int largestPathValue(string color, vector<vector<int>>& edges) {
        int n=color.size(),m=edges.size();
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n,0);
        vector<vector<int>> counts(n,vector<int>(26,0));
        for(int i=0;i<26;i++) counts[0][i]=0;
    
        auto add_edge=[&](int u,int v){
            graph[u].pb(v);
            indegree[v]++;
        };
    
        for(int i=0;i<n;i++){
            counts[i][color[i]-'a']++;
        }

        for(auto &itr:edges){
            add_edge(itr[0],itr[1]);
        };

        // debug(indegree);
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
    
        int vis=0;
        int max_ele=0;
    
        while(q.size()>0){
            int node=q.front();
            q.pop();
            vis++;
            for(int nbr:graph[node]){
                for(int i=0;i<26;i++){
                    counts[nbr][i]=max(counts[nbr][i],counts[node][i]+(((color[nbr]-'a')==i) ? 1 : 0));
                }
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
            max_ele=max(max_ele,*max_element(counts[node].begin(),counts[node].end()));
        }
    
        return ((vis==n) ? max_ele : -1);
    }
};