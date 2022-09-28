class Solution {
public:
    int solve(int s,int e,vector<vector<int>>& dp)
    {
        if(s>=e)
            return 0;
        if(dp[s][e]!=0)
            return dp[s][e];
        int temp=INT_MAX;
        for(int i=s;i<e;i++)
        {
            int cost=i+max(solve(s,i-1,dp),solve(i+1,e,dp));
            temp=min(temp,cost);
        }
        dp[s][e]=temp;
        return temp;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return solve(1,n,dp);
    }
};