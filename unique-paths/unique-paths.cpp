class Solution {
public:
    // recursive
    //  int dx[2]={1,0};
    // int dy[2]={0,1};
    
    /*
    bool isvalid(int x,int y,int m,int n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int uniquerec(int start,int end,int m,int n)
    {
        if(start==m-1 && end==n-1)
            return 1;
        int ans=0;
        for(int i=0;i<2;i++)
        {
            int newx=start+dx[i];
            int newy=end+dy[i];
            if(isvalid(newx,newy,m,n))
             ans+= uniquerec(newx,newy,m,n);     
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return uniquerec(0,0,m,n);
    }
    
    */
    
     // top-down(memoization)
    /*
    int dx[2]={1,0};
    int dy[2]={0,1};
    int dp[101][101];
    bool isvalid(int x,int y,int m,int n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int uniquerec(int start,int end,int m,int n)
    {
        if(start==m-1 && end==n-1)
            return 1;
        int ans=0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        for(int i=0;i<2;i++)
        {
            int newx=start+dx[i];
            int newy=end+dy[i];
            if(isvalid(newx,newy,m,n))
             ans+= uniquerec(newx,newy,m,n);     
        }
        return dp[start][end]=ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return uniquerec(0,0,m,n);
    }
    */
    
    //bottom-up(dp)
    int dx[2]={1,0};
    int dy[2]={0,1};
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=1;
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
