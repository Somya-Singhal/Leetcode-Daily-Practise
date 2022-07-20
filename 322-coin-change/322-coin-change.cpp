class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
//         int dp[n+1][amount+1];
        
//         for(int j=0;j<=amount;j++)
//             dp[0][j]=INT_MAX-1;
//         for(int i=0;i<=n;i++)
//             dp[i][0]=0;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=amount;j++)
//             {
//                 if(coins[i-1]<=j)
//                     dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
//                 else
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         return (dp[n][amount]==INT_MAX-1?-1:dp[n][amount]);
        vector<int>dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                    dp[i]=min(1+dp[i-coins[j]],dp[i]);
            }
              
        }
        return (dp[amount]==INT_MAX-1?-1:dp[amount]);
    }
};