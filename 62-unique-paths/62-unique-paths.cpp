class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>grid(m,vector<int>(n,0));
    //     for(int i=0;i<n;i++)
    //         grid[0][i]=1;
    //     for(int j=0;j<m;j++)
    //         grid[j][0]=1;
    //     for(int i=1;i<m;i++)
    //     {
    //         for(int j=1;j<n;j++)
    //         {
    //             grid[i][j]=grid[i-1][j]+grid[i][j-1];
    //         }
    //     }
    //     return grid[m-1][n-1];
    // }
    
     int uniquePaths(int m, int n) {
        vector<int>pre(n,1),curr(n,1);
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                curr[j]=pre[j]+curr[j-1];
            }
            swap(pre,curr);
        }
        return pre[n-1];
    }
};