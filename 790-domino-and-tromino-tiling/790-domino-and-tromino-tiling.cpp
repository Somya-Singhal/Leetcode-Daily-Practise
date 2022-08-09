class Solution {
public:
    int mod=1e9+7;
//     int numTilings(int n) {
//         vector<int>dp(1001,0);
//         dp[0]=1,dp[1]=1,dp[2]=2;
        
//         for(int i=3;i<=n;i++)
//             dp[i]=((2*dp[i-1]%mod)%mod+dp[i-3]%mod)%mod;
//         return dp[n];
//     }
    int dp[1001][2];
    int solve(int i,bool prevGap,int n)
    {
        if(i>n)
            return 0;
        if(i==n)
            return !prevGap;
        if(dp[i][prevGap]!=-1)
            return dp[i][prevGap];
        if(!prevGap)
            return dp[i][prevGap]=(solve(i+1,false,n)+solve(i+2,false,n)+2l*solve(i+2,true,n))%mod;
        return dp[i][prevGap]=(solve(i+1,false,n)+solve(i+1,true,n))%mod;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,false,n);
    }
};