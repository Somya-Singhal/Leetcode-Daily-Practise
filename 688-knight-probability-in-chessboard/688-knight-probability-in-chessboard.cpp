class Solution {
public:
    int dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={1,2,2,1,-1,-2,-2,-1};
    
    double dp[101][26][26];
    double solve(int n, int k, int x, int y)
    {
        if(x<0 || x>=n || y<0 || y>=n)
            return 0;
        if(k==0)
            return 1;
        
        if(dp[k][x][y]!=0)
            return dp[k][x][y];
        double ways=0;
        for(int i=0;i<8;i++)
        {
            ways+=0.125*solve(n,k-1,x+dx[i],y+dy[i]);
        }
        dp[k][x][y]=ways;
        return dp[k][x][y];
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return solve(n,k,row,column);
    }
};