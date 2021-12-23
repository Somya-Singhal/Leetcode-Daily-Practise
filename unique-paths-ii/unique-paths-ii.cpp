class Solution {
public:
    //recursive
    // int uniquePathsrec(int i,int j,int n,int m,vector<vector<int>>& obstacleGrid)
    // {
    //         if(i<0 || i>=n || j<0 || j>=m || obstacleGrid[i][j]==1)
    //             return 0;
    //         if(i==n-1 && j==m-1 && obstacleGrid[n-1][m-1]==0)
    //             return 1;
    //         int left=0,right=0;
    //         left=uniquePathsrec(i+1,j,n,m,obstacleGrid);
    //         right=uniquePathsrec(i,j+1,n,m,obstacleGrid);
    //     return left+right;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int n=obstacleGrid.size();
    //     int m=obstacleGrid[0].size();
    //     return uniquePathsrec(0,0,n,m,obstacleGrid);
    // }
    
    //dp->space-->O(mn)
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n=obstacleGrid.size();
//         int m=obstacleGrid[0].size();
//         int dp[n][m];
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(obstacleGrid[i][j]==1)
//                     dp[i][j]=0;
//                 else
//                 {
//                     if(i==0 && j==0)
//                         dp[i][j]=1;
//                     else if(i==0)
//                         dp[i][j]=dp[i][j-1];
//                     else if(j==0)
//                         dp[i][j]=dp[i-1][j];
//                     else
//                         dp[i][j]=dp[i-1][j]+dp[i][j-1];
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
    
     //dp-->space-->O(m)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[m];
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
            return 0;
        dp[0]=1;
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[0][i]==1)
                dp[i]=0;
            else
                dp[i]=dp[i-1];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                  dp[j]=0;
                else if(j!=0)
                    dp[j]+=dp[j-1];
            }
        }
        return dp[m-1];
    }
};
