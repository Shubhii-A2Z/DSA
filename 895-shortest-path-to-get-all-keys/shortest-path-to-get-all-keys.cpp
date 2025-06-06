class Solution {
public:
    struct pr{
        int a,b,c; //{mask of keys,i,j}
    };

    vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1}};

    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(), m=grid[0].size();

        int x,y,maxLen=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                char ch=grid[i][j];
                if(ch=='@'){
                    x=i; y=j;
                }
                if(ch>='a' && ch<='f') maxLen=max(ch-'a'+1,maxLen);
            }
        }

        queue<pr> q;
        q.push({0,x,y});
        unordered_set<string> vis;
        vis.insert(to_string(0)+" "+to_string(x)+" "+to_string(y));

        int steps=0;
        while(q.size()){
            int sze=q.size();
            while(sze--){
                auto curr=q.front(); q.pop();
                int mask=curr.a, i=curr.b, j=curr.c;
                if(mask==(1<<maxLen)-1) return steps;
                for(auto &d:dir){
                    int i_=i+d.first, j_=j+d.second;
                    if(i_>=n || i_<0 || j_>=m || j_<0) continue;
                    char ch=grid[i_][j_];
                    if(ch=='#') continue;
                    if(ch>='A' && ch<='F' && !(mask & (1<<(ch-'A')))) continue; // we dont have key for the lock
                    int newMask=mask; //each neighbor move should track its own version of the key set
                    if(ch>='a' && ch<='f') newMask|=(1<<(ch-'a')); // we found a key
                    if(!vis.count(to_string(newMask)+" "+to_string(i_)+" "+to_string(j_))){
                        vis.insert(to_string(newMask)+" "+to_string(i_)+" "+to_string(j_));
                        q.push({newMask,i_,j_});
                    }
                }
            }
            steps++; // we moved one step forward
        }

        return -1;
    }
};