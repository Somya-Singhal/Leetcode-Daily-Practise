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
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                {
                    if(i==0 && j==0)
                        dp[i][j]=1;
                    else if(i==0)
                        dp[i][j]=dp[i][j-1];
                    else if(j==0)
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};