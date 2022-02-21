class Solution {
public:
    
   bool ispresent(int idx,int currRow,int currCol,int totalRow,int totalCol,vector<vector<char>>& board,string word){
       if(idx==word.length())
           return true;
       if(currRow<0 || currRow>=totalRow || currCol<0 || currCol>=totalCol || word[idx]!=board[currRow][currCol])
           return false;
       char c=board[currRow][currCol];
       board[currRow][currCol]='.';
       bool flag=ispresent(idx+1,currRow-1,currCol,totalRow,totalCol,board,word) || ispresent(idx+1,currRow+1,currCol,totalRow,totalCol,board,word) || ispresent(idx+1,currRow,currCol-1,totalRow,totalCol,board,word) || ispresent(idx+1,currRow,currCol+1,totalRow,totalCol,board,word);
       board[currRow][currCol]=c;
       return flag;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ispresent(0,i,j,m,n,board,word))
                    return true;
          
            }
        }
        return false;
    }
};