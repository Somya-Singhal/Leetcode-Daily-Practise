class Solution {
public:
    int mod=1e9+7;
    int numTilings(int n) {
        vector<int>dp(1001,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        
        for(int i=3;i<=n;i++)
            dp[i]=((2*dp[i-1]%mod)%mod+dp[i-3]%mod)%mod;
        return dp[n];
    }
};