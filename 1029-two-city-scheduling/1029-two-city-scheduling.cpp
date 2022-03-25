class Solution {
public:
    int solve(int idx,int n,int na,int nb,vector<vector<int>>& costs,vector<vector<int>>& dp)
    {
        if(idx==n)
            return 0;
        if(dp[na][nb]!=-1)
            return dp[na][nb];
        int sum1=0,sum2=0;
        if(na>0 || nb>0)
        {
            if(na>0) sum1+=costs[idx][0]+solve(idx+1,n,na-1,nb,costs,dp);
            else sum1=INT_MAX;
            if(nb>0) sum2+=costs[idx][1]+solve(idx+1,n,na,nb-1,costs,dp);
            else
                sum2=INT_MAX;
        }
        return dp[na][nb]=min(sum1,sum2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>dp(n/2+1,vector<int>(n/2+1,-1));
        return solve(0,n,n/2,n/2,costs,dp);
    }
};