class Solution {
public:
    
    //recursive
    // int coinrec(int index,vector<int>& coins, int amount)
    // {
    //     if(amount==0)
    //         return 0;
    //     if(amount<0 || index>=coins.size())
    //         return INT_MAX;
    //     if(coins[index]<=amount)
    //     return min(1+coinrec(index,coins,amount-coins[index]),coinrec(index+1,coins,amount));
    //     else
    //         return coinrec(index+1,coins,amount);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int num=coinrec(0,coins,amount);
    //     return (num==INT_MAX)?-1:num;
    // }
    
    // dp
    int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size()+1][amount+1];
        for(int i=0;i<=coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=INT_MAX-1;
                else if(j==0)
                    dp[i][j]=0;
                else if(i==1)
                {
                    if(j%coins[0]==0)
                        dp[1][j]=j/coins[0];
                    else
                        dp[1][j]=INT_MAX-1;
                }
                else if(coins[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return (dp[coins.size()][amount]==INT_MAX-1)?-1:dp[coins.size()][amount];
    }
};