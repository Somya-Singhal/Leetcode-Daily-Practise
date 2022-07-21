class Solution {
public:
    int solve(int i,int curr,vector<int>& days, vector<int>& costs,vector<vector<int>>& dp)
    {
        int n=days.size();
        if(i==n)
            return 0;
        if(dp[i][curr]!=INT_MAX)
            return dp[i][curr];
        if(curr>days[i])
            return dp[i][curr]=solve(i+1,curr,days,costs,dp);
        else if(curr==days[i])
        {
            int a=costs[0]+solve(i+1,curr+1,days,costs,dp);
            int b=costs[1]+solve(i+1,curr+7,days,costs,dp);
            int c=costs[2]+solve(i+1,curr+30,days,costs,dp);
            return dp[i][curr]=min(a,min(b,c));
        }
        else
        return dp[i][curr]=solve(i,curr+1,days,costs,dp);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>>dp(n+1,vector<int>(1000,INT_MAX));
        return solve(0,0,days,costs,dp);
    }
};