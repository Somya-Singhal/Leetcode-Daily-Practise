class Solution {
public:
    int mod=1e9+7;
    
    int solve(int i,int sum,int n,int k,int target,vector<vector<int>>& dp)
    {
        if(i==n)
            return (sum==target);
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int ways=0;
        for(int j=1;j<=min(k,target-sum);j++)
        {
            ways=(ways+solve(i+1,sum+j,n,k,target,dp))%mod;
        }
        return dp[i][sum]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return solve(0,0,n,k,target,dp);
    }
};