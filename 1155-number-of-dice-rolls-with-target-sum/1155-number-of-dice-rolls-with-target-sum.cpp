class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int k,int target,vector<vector<int>>& dp)
    {
        if(n==0 && target==0)
            return 1;
        if(target<0 || n<0)
            return 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
        int count=0;
        for(int m=1;m<=k;m++)
        {
            count=(count+solve(n-1,k,target-m,dp))%mod;
        }
        dp[n][target]=count;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};