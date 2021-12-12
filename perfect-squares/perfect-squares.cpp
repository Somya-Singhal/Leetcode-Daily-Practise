class Solution {
public:
    // recursive
    //  int Squaresrec(int l,int r,int num,int n)
    // {
    //     if(l>r)
    //         return INT_MAX-1;
    //     if(num==n && l<=r)
    //         return 0;
    //     if(l*l<=n-num)
    //     return min(1+Squaresrec(l,r,num+l*l,n),Squaresrec(l+1,r,num,n));
    //     else
    //     return Squaresrec(l+1,r,num,n);
    // }
    // int numSquares(int n) {
    //     int r=sqrt(n);
    //     return Squaresrec(1,r,0,n);
    // }
    int numSquares(int n) {
        int r=sqrt(n);
        int dp[r+1][n+1];
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=INT_MAX-1;
                else if(j==0)
                    dp[i][j]=0;
                else if(i*i<=j)
                    dp[i][j]=min(1+dp[i][j-i*i],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[r][n];
    }
};