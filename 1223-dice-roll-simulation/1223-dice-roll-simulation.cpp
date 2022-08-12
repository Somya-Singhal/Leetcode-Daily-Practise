class Solution {
public:
    int mod=1e9+7;
    int dp[5001][6][16];
    int solve(int n,int prev,int len,vector<int>& rollMax)
    {
        if(n==0)
          return 1;
        if(prev>=0 && dp[n][prev][len]!=-1)
            return dp[n][prev][len];
        int ways=0;
        for(int i=0;i<6;i++)
        {
            if(prev==i && len==rollMax[i])
                continue;
            ways=(ways+solve(n-1,i,i==prev?len+1:1,rollMax))%mod;
        }
        if(prev>=0)
        dp[n][prev][len]=ways;
        return ways;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return solve(n,-1,0,rollMax);
    }
};