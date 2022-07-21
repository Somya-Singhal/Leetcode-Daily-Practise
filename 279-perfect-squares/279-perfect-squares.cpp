class Solution {
public:
   
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=INT_MAX-1;
            for(int j=1;j*j<=n;j++)
            {
               if(i>=(j*j))
                dp[i]=min(1+dp[i-(j*j)],dp[i]);   
            }
        }
        return dp[n];
    }
};