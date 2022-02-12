class Solution {
public:
    bool isvalid(int i,int j,char k,vector<vector<char>>& board)
    {
        for(int idx=0;idx<9;idx++)
        {
            if(board[i][idx]==k || board[idx][j]==k || (board[3*(i/3)+idx/3][3*(j/3)+idx%3]!='.' && board[3*(i/3)+idx/3][3*(j/3)+idx%3]==k))
                return false;
           
        }
        
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>& board)
    {
        if(i==9)
            return true;
        if(j==9)
            return solve(i+1,0,board);
        if(board[i][j]!='.')
            return solve(i,j+1,board);
        for(char k='1';k<='9';k++)
         {
           if(isvalid(i,j,k,board))
            {
                board[i][j]=k;
                if(solve(i,j+1,board))
                    return true;
                board[i][j]='.';
            }
         }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};