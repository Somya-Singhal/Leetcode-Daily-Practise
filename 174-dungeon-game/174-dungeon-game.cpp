class Solution {
public:
   
//     int solve(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& dungeon)
//     {
//         int n=dungeon.size(),m=dungeon[0].size();
//         if(row==n || col==m)
//             return INT_MAX;
//         if(row==n-1 && col==m-1)
//             return (dungeon[row][col]<=0)?-dungeon[row][col]+1:1;
//         if(dp[row][col]!=INT_MAX)
//             return dp[row][col];
//         int right=solve(row,col+1,dp,dungeon);
//         int down=solve(row+1,col,dp,dungeon);
//         int ans=min(right,down)-dungeon[row][col];
        
//         return dp[row][col]=(ans<=0)?1:ans;
//     }
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         int n=dungeon.size(),m=dungeon[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        
//         return solve(0,0,dp,dungeon);
//     }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[n-1][m-1]=(dungeon[n-1][m-1]<=0)?-dungeon[n-1][m-1]+1:1;
        for(int i=n-2;i>=0;i--)
        {
            
            int temp=dp[i+1][m-1]-dungeon[i][m-1];
            dp[i][m-1]=(temp<=0)?1:temp;
        }
            
        for(int j=m-2;j>=0;j--)
        {
            int temp=dp[n-1][j+1]-dungeon[n-1][j];
             dp[n-1][j]=(temp<=0)?1:temp;
        }
           
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                int temp=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j]=(temp<=0)?1:temp;
            }
        }
        return dp[0][0];
    }
};