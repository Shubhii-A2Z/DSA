class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& v) {

        auto updateGrid=[&]()->vector<vector<char>>{
            vector<vector<char>> ans(v[0].size(),vector<char>(v.size()));
            for(int i=0;i<v[0].size();++i){
                for(int j=0;j<v.size();++j){
                    ans[i][j]=v[v.size()-1-j][i];
                }
            }
            return ans;
        };

        for(int i=0;i<v.size();++i){ // for each row
            int j=v[i].size()-1; // starting from xtreme right
            while(j>=0 && v[i][j]!='.') j--;
            if(j<0) continue;
            int justRightObs=j;
            for(int k=j-1;k>=0;--k){
                if(v[i][k]=='*') justRightObs=k;
                else if(v[i][k]=='.' && justRightObs<j) j=k;
                else if(v[i][k]=='#'){ //stone found
                    if(v[i][k+1]=='#' || v[i][k+1]=='*') continue; 
                    v[i][j]='#'; v[i][k]='.';
                    while(j>=0 && v[i][j]!='.') j--;
                    if(j<0) break; 
                }
            }
        }
        
        v=updateGrid();
        for(auto &x:v){
            for(auto &ele:x){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return v;
    }
};