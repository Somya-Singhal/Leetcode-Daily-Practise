class Solution {
public:
    int mod=1e9+7;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    int dp[51][51][51];
    int solve(int m, int n, int maxMove, int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return 1;
        if(maxMove<=0)
            return 0;
        if(dp[maxMove][x][y]!=-1)
            return dp[maxMove][x][y];
        int ways=0;
        for(int i=0;i<4;i++)
        {
            ways=(ways+solve(m,n,maxMove-1,x+dx[i],y+dy[i]))%mod;
        }
        dp[maxMove][x][y]=ways;
        return dp[maxMove][x][y];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};