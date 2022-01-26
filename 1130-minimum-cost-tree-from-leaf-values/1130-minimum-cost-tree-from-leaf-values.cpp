class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(j==i+1)
                    dp[i][j]=arr[i]*arr[j];
                else
                {
                    int ans=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        int maxx=INT_MIN,maxy=INT_MIN;
                        for(int t=i;t<=k;t++)
                        {
                            maxx=max(maxx,arr[t]);
                        }  
                        for(int t=k+1;t<=j;t++)
                        {
                            maxy=max(maxy,arr[t]);
                        }
                        // cout<<maxx*maxy+dp[i][k]+dp[k+1][j]<<endl;
                        ans=min(ans,maxx*maxy+dp[i][k]+dp[k+1][j]);
                        dp[i][j]=ans;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};