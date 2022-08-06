class Solution {
public:
    // int solve(int n)
    // {
    //     if(n==0)
    //         return 1;
    //     if(n<0)
    //         return 0;
    //     return solve(n-1)+solve(n-2);
    // }
    // int climbStairs(int n) {
    //     return solve(n);
    // }
    
    // int climbStairs(int n) {
    //    vector<int>dp(n+1,0);
    //    dp[0]=1,dp[1]=1;
    //     for(int i=2;i<=n;i++)
    //         dp[i]=dp[i-1]+dp[i-2];
    //     return dp[n];
    // }
    
    int climbStairs(int n) {
       int num1=1,num2=1;
      
        for(int i=2;i<=n;i++)
        {
            int curr=num1+num2;
            num1=num2;
            num2=curr;
        }
        return num2;
    }
};