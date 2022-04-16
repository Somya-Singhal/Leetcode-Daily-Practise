class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        vector<vector<long>>dp(n+1,vector<long>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[j+1][i]=(dist[j]+dp[j][i]+speed-1)/speed*speed;
                if(i>0)
                    dp[j+1][i]=min(dp[j+1][i],dist[j]+dp[j][i-1]);
            }
            if(dp[n][i]<=(long)speed*hoursBefore)
                return i;
        }
        return -1;
    }
};