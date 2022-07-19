class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int m=grid.size(),n=grid[0].size();
        // for(int i=m-1;i>=0;i--)
        // {
        //     for(int j=n-1;j>=0;j--)
        //     {
        //         if(i==m-1 && j==n-1)
        //             continue;
        //         if(i==m-1)
        //             grid[i][j]+=grid[i][j+1];
        //         else if(j==n-1)
        //             grid[i][j]+=grid[i+1][j];
        //         else
        //         {
        //             grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);
        //         }
        //     }
        // }
        // return grid[0][0];
        
        int m=grid.size(),n=grid[0].size();
        vector<int>pre(m,grid[m-1][n-1]),curr(m,0);
        for(int i=m-2;i>=0;i--)
            pre[i]=pre[i+1]+grid[i][n-1];
        for(int j=n-2;j>=0;j--)
        {
            curr[m-1]=pre[m-1]+grid[m-1][j];
            for(int i=m-2;i>=0;i--)
            {
                curr[i]=min(curr[i+1],pre[i])+grid[i][j];
            }
            pre=curr;
        }
        return pre[0];
        
        // int m=grid.size(),n=grid[0].size();
        // vector<int>curr(m,grid[0][0]);
        // for(int i=1;i<m;i++)
        //     curr[i]=curr[i-1]+grid[i][0];
        // for(int j=1;j<n;j++)
        // {
        //     curr[0]+=grid[0][j];
        //     for(int i=1;i<m;i++)
        //     {
        //         curr[i]=min(curr[i-1],curr[i])+grid[i][j];
        //     }
        // }
        // return curr[m-1];
    }
};