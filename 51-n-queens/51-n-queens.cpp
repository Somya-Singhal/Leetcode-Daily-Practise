class Solution {
public:
    // bool isvalid(vector<string>& res,int i,int j)
    // {
    //     int n=res.size();
    //     for(int k=0;k<n;k++)
    //     {
    //         if(res[i][k]=='Q' || res[k][j]=='Q')
    //             return false;
    //     }
    //     for(int row=i-1,col=j-1;row>=0 && col>=0;row--,col--)
    //     {
    //         if(res[row][col]=='Q')
    //             return false;
    //     }
    //     for(int row=i-1,col=j+1;row>=0 && col<n;row--,col++)
    //     {
    //         if(res[row][col]=='Q')
    //             return false;
    //     }
    //     return true;
    // }
    // void solve(vector<vector<string>>& grid,vector<string>& res,int row,int n) {
    //     if(row==n)
    //     {
    //         grid.push_back(res);
    //         return;
    //     }
    //     for(int col=0;col<n;col++)
    //     {
    //         if(isvalid(res,row,col))
    //         {
    //             res[row][col]='Q';
    //             solve(grid,res,row+1,n);
    //             res[row][col]='.';
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>grid;
    //     vector<string>res(n,string(n,'.'));
    //     solve(grid,res,0,n);
    //     return grid;
    // }
    
    // void solve(vector<vector<string>>& grid,vector<string>& res,vector<int>& flag_col,vector<int>& flag_45,vector<int>& flag_135,int row,int n)
    // {
    //     if(row==n)
    //     {
    //         grid.push_back(res);
    //         return;
    //     }
    //     for(int col=0;col<n;col++)
    //     {
    //         if(flag_col[col] && flag_45[col+row] && flag_135[n-1+col-row])
    //         {
    //             flag_col[col]=flag_45[col+row]=flag_135[n-1+col-row]=0;
    //             res[row][col]='Q';
    //             solve(grid,res,flag_col,flag_45,flag_135,row+1,n);
    //             res[row][col]='.';
    //             flag_col[col]=flag_45[col+row]=flag_135[n-1+col-row]=1;
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>grid;
    //     vector<string>res(n,string(n,'.'));
    //     vector<int>flag_col(n,1),flag_45(2*n-1,1),flag_135(2*n-1,1);
    //     solve(grid,res,flag_col,flag_45,flag_135,0,n);
    //     return grid;
    // }
    
     void solve(vector<vector<string>>& grid,vector<string>& res,vector<int>& flag,int row,int n)
    {
        if(row==n)
        {
            grid.push_back(res);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(flag[col] && flag[n+col+row] && flag[4*n-2+col-row])
            {
                flag[col]=flag[n+col+row]=flag[4*n-2+col-row]=0;
                res[row][col]='Q';
                solve(grid,res,flag,row+1,n);
                res[row][col]='.';
                flag[col]=flag[n+col+row]=flag[4*n-2+col-row]=1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>grid;
        vector<string>res(n,string(n,'.'));
        vector<int>flag(5*n-2,1);
        solve(grid,res,flag,0,n);
        return grid;
    }
};