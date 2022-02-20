class Solution {
public:
    bool isvalid(vector<string>& res,int i,int j)
    {
        int n=res.size();
        for(int k=0;k<n;k++)
        {
            if(res[i][k]=='Q' || res[k][j]=='Q')
                return false;
        }
        for(int row=i-1,col=j-1;row>=0 && col>=0;row--,col--)
        {
            if(res[row][col]=='Q')
                return false;
        }
        for(int row=i-1,col=j+1;row>=0 && col<n;row--,col++)
        {
            if(res[row][col]=='Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& grid,vector<string>& res,int row,int n) {
        if(row==n)
        {
            grid.push_back(res);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isvalid(res,row,col))
            {
                res[row][col]='Q';
                solve(grid,res,row+1,n);
                res[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>grid;
        vector<string>res(n,string(n,'.'));
        solve(grid,res,0,n);
        return grid;
    }
};