class Solution {
public:
    // int solve(int i,int curr,vector<int>& days, vector<int>& costs,vector<vector<int>>& dp)
    // {
    //     int n=days.size();
    //     if(i==n || curr>365)
    //         return 0;
    //     if(dp[i][curr]!=INT_MAX)
    //         return dp[i][curr];
    //     if(curr>days[i])
    //         return dp[i][curr]=solve(i+1,curr,days,costs,dp);
    //     else if(curr==days[i])
    //     {
    //         int a=costs[0]+solve(i+1,curr+1,days,costs,dp);
    //         int b=costs[1]+solve(i+1,curr+7,days,costs,dp);
    //         int c=costs[2]+solve(i+1,curr+30,days,costs,dp);
    //         return dp[i][curr]=min(a,min(b,c));
    //     }
    //     else
    //     return dp[i][curr]=solve(i,curr+1,days,costs,dp);
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     int n=days.size();
    //     vector<vector<int>>dp(n+1,vector<int>(366,INT_MAX));
    //     return solve(0,0,days,costs,dp);
    // }
    
     int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size(),len=days[n-1];
        unordered_set<int>s(begin(days),end(days));
        vector<int>dp(len+1,0);
        for(int i=days[0];i<=len;i++)
        {
            if(s.find(i)==s.end())
                dp[i]=dp[i-1];
            else
            dp[i]=min({dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
        }
         return dp[len];
    }
};