class Solution {
public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         int dp[k+1][n+1];
//         for(int i=0;i<=n;i++)
//             dp[0][i]=0;
//         for(int i=0;i<=k;i++)
//             dp[i][0]=0;
//         for(int i=1;i<k+1;i++)
//         {
//             int currmax=INT_MIN;
//             for(int j=1;j<n+1;j++)
//             {
//                 if(dp[i-1][j-1]-prices[j-1]>currmax)
//                 currmax=dp[i-1][j-1]-prices[j-1];
                
//                 dp[i][j]=max(currmax+prices[j-1],dp[i][j-1]);
//             }
            
//         }
//         return dp[k][n];
//     }
    
    //state machine
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>buy(k+1,INT_MIN),sell(k+1,0);
        if(k>=n/2)
        {
            int ans=0;
            for(int i=0;i<n-1;i++)
            {
                if(prices[i+1]>prices[i])
                  ans+=prices[i+1]-prices[i];  
            }
            return ans;
        }
        for(auto x: prices)
        {
            for(int i=1;i<=k;i++)
            {
                buy[i]=max(buy[i],sell[i-1]-x);
                sell[i]=max(sell[i],buy[i]+x);
            }
        }
        return sell[k];
    }
};