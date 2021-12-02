class Solution {
public:
    
    // recursive
    // int climbStairs(int n) {
    //     if(n<0)
    //         return 0;
    //     if(n==0)
    //         return 1;
    //     int onesteps=0,twosteps=0;
    //     onesteps+=climbStairs(n-1);
    //     twosteps+=climbStairs(n-2);
    //     return onesteps+twosteps;
    // }
    
    // dp
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};