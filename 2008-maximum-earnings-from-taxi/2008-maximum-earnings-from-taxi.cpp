class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long>dp(n+1,0);
        sort(rides.begin(),rides.end());
        int j=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i],dp[i-1]);
            while(j<rides.size() && rides[j][0]==i)
            {
                dp[rides[j][1]]=max(dp[rides[j][1]],dp[i]+rides[j][1]-rides[j][0]+rides[j][2]);
                j++;
            }
        }
        return dp[n];
    }
};