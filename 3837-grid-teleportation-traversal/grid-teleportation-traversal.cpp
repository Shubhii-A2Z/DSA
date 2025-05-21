class Solution {
public:
    typedef pair<int,int> pr;
    vector<pr> dir={{1,0},{-1,0},{0,-1},{0,1}};

    int minMoves(vector<string>& mat) {
        int n=mat.size(), m=mat[0].size();

        unordered_map<char,vector<pr>> mp;
        unordered_set<char> vis;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]>='A' && mat[i][j]<='Z') mp[mat[i][j]].push_back({i,j});
            }
        }

        queue<pair<int,pr>> dq;
        dq.push({0,{0,0}});

        if(mat[0][0]>='A' && mat[0][0]<='Z'){
            for(auto &itr:mp[mat[0][0]]){
                int nextI=itr.first, nextJ=itr.second;
                if(nextI==0 && nextJ==0) continue;
                dq.push({0,{nextI,nextJ}});
            }
            vis.insert(mat[0][0]);
        }


        while(dq.size()){
            auto curr=dq.front();
            dq.pop();
            int cost=curr.first, i=curr.second.first, j=curr.second.second;

            if(i==n-1 && j==m-1) return cost;

            for(int d=0;d<4;++d){
                int i_=i+dir[d].first, j_=j+dir[d].second;

                if(i_<0 || i_>=n || j_<0 || j_>=m || mat[i_][j_]=='#') continue;
                
                dq.push({cost+1,{i_,j_}});

                if(mat[i_][j_]!='.' && !vis.count(mat[i_][j_])){
                    for(auto &itr:mp[mat[i_][j_]]){
                        int nextI=itr.first, nextJ=itr.second;
                        if(nextI==i_ && nextJ==j_) continue;
                        dq.push({cost+1,{nextI,nextJ}});
                        mat[nextI][nextJ]='#'; //marking cell visited
                    }
                    vis.insert(mat[i_][j_]);
                }

                mat[i_][j_]='#'; //marking cell visited
            }
        }

        return -1;
    }

};