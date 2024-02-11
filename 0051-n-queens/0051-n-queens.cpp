class Solution {
public:
    bool isSafe(int r,int c,vector<string>& v,int n){
        for(int i=0;i<c;i++){
            if(v[r][i]=='Q')
                return false;
        }
        for(int i=0;i<r;i++){
            if(v[i][c]=='Q')
                return false;
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(v[i][j]=='Q')
              return false;
        }
        for(int i=r+1,j=c-1;i<n && j>=0;i++,j--){
            if(v[i][j]=='Q')
                return false;
        }
        return true;  
    }
    void helper(int col,int n,vector<vector<string>>& board,vector<string>v){
        if(col==n){
            board.push_back(v);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,v,n)){
                v[row][col]='Q';
                helper(col+1,n,board,v);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>board;
        string str(n,'.');
        vector<string>v(n,str);

        helper(0,n,board,v);
        return board;
    }
};