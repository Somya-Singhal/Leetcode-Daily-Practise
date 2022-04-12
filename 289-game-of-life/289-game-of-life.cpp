class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>adj(n,vector<int>(m,0));
        int dirx[8]={0,1,1,1,0,-1,-1,-1};
        int diry[8]={1,1,0,-1,-1,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int count=0;
                  for(int k=0;k<8;k++){
                      int newx=i+dirx[k],newy=j+diry[k];
                      if(newx>=0 && newx<n && newy>=0 && newy<m){
                          if(board[newx][newy]==1)
                          count++;
                      }
                  }
                if(board[i][j]==0){
                    if(count==3)
                        adj[i][j]=1;
                } else {
                    if(count<2 || count>3)
                       adj[i][j]=0;
                    else if(count==2 || count==3)
                        adj[i][j]=1;
                }
            }
        }
        board=adj;
    }
};