class Solution {
public:
    // int solve(vector<int>& values,int i,int j,vector<vector<int>>& dp)
    // {
    //     if(i+1==j)
    //         return 0;
    //     if(dp[i][j]!=INT_MAX)
    //         return dp[i][j];
    //     int ans=INT_MAX;
    //     for(int k=i+1;k<j;k++)
    //         ans=min(ans,values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp));
    //     return dp[i][j]=ans;
    // }
    // int minScoreTriangulation(vector<int>& values) {
    //     int n=values.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
    //     return solve(values,0,n-1,dp);
    // }
    
     int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=1;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(i==j || i+1==j)
                    continue;
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++)
                    ans=min(ans,values[i]*values[k]*values[j]+dp[i][k]+dp[k][j]);
                dp[i][j]=ans;
            }
        }
         return dp[0][n-1];
       
    }
};