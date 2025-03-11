class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<int> st, ed, currParent;

    void EulerTour(int node,int par,int &idx){
        st[node]=idx;
        currParent[node]=par;
        for(auto &nbr:graph[node]){
            if(nbr==par) continue;
            idx++;
            EulerTour(nbr,node,idx);
        }
        ed[node]=idx;
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int nodes=edges.size()+1;
        st.resize(nodes); ed.resize(nodes); currParent.resize(nodes);

        for(auto &edge:edges){
            int u=edge[0], v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int idx=0;
        EulerTour(0,-1,idx); // Starting EuelrTour with tree rooted at 0

        vector<int> ans(nodes+1,0);
        for(auto &guess:guesses){
            int u=guess[0], v=guess[1];
            if(currParent[v]==u){
                ans[st[0]]++; //difference array technique
                ans[st[v]]--; ans[ed[v]+1]++;
            }
            else{
                ans[st[u]]++; ans[ed[u]+1]--; //difference array technique
            }
        }

        for(int i=1;i<ans.size();++i){
            ans[i]+=ans[i-1];
        }

        int cnt=0;
        for(int i=0;i<nodes;++i){
            if(ans[st[i]]>=k) cnt++;
        }

        return cnt;
    }
};