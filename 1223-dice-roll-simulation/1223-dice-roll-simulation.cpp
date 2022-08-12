class Solution {
public:
    int mod=1e9+7;
    // int dp[5001][6][16];
    // int solve(int n,int prev,int len,vector<int>& rollMax)
    // {
    //     if(n==0)
    //       return 1;
    //     if(prev>=0 && dp[n][prev][len]!=-1)
    //         return dp[n][prev][len];
    //     int ways=0;
    //     for(int i=0;i<6;i++)
    //     {
    //         if(prev==i && len==rollMax[i])
    //             continue;
    //         ways=(ways+solve(n-1,i,i==prev?len+1:1,rollMax))%mod;
    //     }
    //     if(prev>=0)
    //     dp[n][prev][len]=ways;
    //     return ways;
    // }
    // int dieSimulator(int n, vector<int>& rollMax) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(n,-1,0,rollMax);
    // }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long>>dp(n+1,vector<long>(7,0));
        dp[0][6]=1;
        for(int i=0;i<6;i++)
          dp[1][i]=1;
        dp[1][6]=6;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<6;j++)
            {
                for(int k=1;k<=rollMax[j];k++)
                {
                    if(i-k<0)
                        break;
                    dp[i][j]=((dp[i][j]%mod+dp[i-k][6]%mod)%mod-dp[i-k][j]%mod)%mod;
                }
            }
            long long sum=0;
            for(int j=0;j<6;j++)
                sum=(sum%mod+dp[i][j]%mod)%mod+mod;
            dp[i][6]=sum%mod;
        }
        return dp[n][6]%mod;
    }
};