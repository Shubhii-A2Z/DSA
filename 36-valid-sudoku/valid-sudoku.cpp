class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int r,int c){
        unordered_set<char> down,right,cell;
        for(int i=0;i<9;i++){
            if(board[r][i]!='.' && right.count(board[r][i])) return false;
            else right.insert(board[r][i]);
        }

        for(int i=0;i<9;i++){
            if(board[i][c]!='.' && down.count(board[i][c])) return false;
            else down.insert(board[i][c]);
        }

        int x=(r/3)*3;
        int y=(c/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]!='.' && cell.count(board[i][j])) return false;
                else cell.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    char num=board[i][j];
                    if(!isSafe(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};