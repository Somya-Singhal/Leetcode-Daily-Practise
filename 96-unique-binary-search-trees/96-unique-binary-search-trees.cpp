class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int gap=1;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==1)
                    dp[i][j]=2;
                else
                {
                    dp[i][j]=2*dp[i+1][j];
                    for(int k=0;k<j-1;k++)
                        dp[i][j]+=dp[i][k]*dp[k+2][j];
                }
                 
            }
        }
        return dp[0][n-1];
    }
};