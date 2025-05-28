class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1, m=edges2.size()+1;
        vector<int> distFrom(m,0);

        unordered_map<int,vector<int>> gr1;
        unordered_map<int,vector<int>> gr2;

        for(auto &e:edges1){
            int u=e[0], v=e[1];
            gr1[u].push_back(v);
            gr1[v].push_back(u);
        }

        for(auto &e:edges2){
            int u=e[0], v=e[1];
            gr2[u].push_back(v);
            gr2[v].push_back(u);
        }

        unordered_set<int> vis;

        auto bfs1=[&](int node)->void{
            int lvl=0;
            queue<pair<int,int>> q;
            q.push({node,lvl});
            vis.insert(node);
            bool flag=false;

            while(q.size()){
                int sze=q.size();
                while(sze--){
                    auto [currNode,currLvl]=q.front(); q.pop();
                    if(currLvl>=k){
                        flag=true;
                        break;
                    }
                    if(currLvl>0) distFrom[node]++;
                    for(auto &nbr:gr2[currNode]){
                        if(!vis.count(nbr)){
                            vis.insert(currNode);
                            q.push({nbr,currLvl+1});
                        }
                    }
                }
                if(flag) break;
            }
        };

        auto bfs2=[&](int node)->int{
            int lvl=0, tSum=0;
            queue<pair<int,int>> q;
            q.push({node,lvl});
            vis.insert(node);
            bool flag=false;

            while(q.size()){
                int sze=q.size();
                while(sze--){
                    auto [currNode,currLvl]=q.front(); q.pop();
                    if(currLvl>k){
                        flag=true;
                        break;
                    }
                    if(currLvl>0) tSum++;
                    for(auto &nbr:gr1[currNode]){
                        if(!vis.count(nbr)){
                            vis.insert(currNode);
                            q.push({nbr,currLvl+1});
                        }
                    }
                }
                if(flag) break;
            }
            return tSum;
        };

        for(int i=0;i<m;++i){
            bfs1(i);
            vis.clear();
        }

        // for(auto e:distFrom) cout<<e<<" ";

        int maxe=*max_element(begin(distFrom),end(distFrom));
        vector<int> ans;

        for(int i=0;i<n;++i){
            vis.clear();
            int tNodes=bfs2(i);
            // cout<<tNodes<<" ";
            ans.push_back(k>0 ? tNodes+maxe+2 : 1);
        }

        return ans;
    }
};