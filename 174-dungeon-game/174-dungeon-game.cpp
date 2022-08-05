class Solution {
public:
    // int dp[201][201];
    int solve(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& dungeon)
    {
        int n=dungeon.size(),m=dungeon[0].size();
        if(row==n || col==m)
            return INT_MAX;
        if(row==n-1 && col==m-1)
            return (dungeon[row][col]<=0)?-dungeon[row][col]+1:1;
        if(dp[row][col]!=INT_MAX)
            return dp[row][col];
        int right=solve(row,col+1,dp,dungeon);
        int down=solve(row+1,col,dp,dungeon);
        int ans=min(right,down)-dungeon[row][col];
        // dp[row][col]=(ans<=0)?1:ans;
        return dp[row][col]=(ans<=0)?1:ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        // memset(dp,INT_MAX,sizeof(dp));
        return solve(0,0,dp,dungeon);
    }
};