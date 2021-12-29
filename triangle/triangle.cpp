class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //    for(int i=1;i<n;i++)
    //    {
    //        for(int j=0;j<triangle[i].size();j++)
    //        {
    //            if(j==0)
    //              triangle[i][j]+=triangle[i-1][0];
    //            else if(j==triangle[i].size()-1)
    //                triangle[i][j]+=triangle[i-1][j-1];
    //            else
    //            {
    //                int temp=triangle[i][j];
    //                triangle[i][j]=min(temp+triangle[i-1][j-1],temp+triangle[i-1][j]);
    //            }
    //        }
    //    }
    //    int ans=triangle[n-1][0];
    //    for(int i=1;i<n;i++)
    //    {
    //        ans=min(ans,triangle[n-1][i]);
    //    }
    //     return ans;
    // }
     int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=triangle[i].size()-1;j>=1;j--)
            {
                if(j==triangle[i].size()-1)
                    dp[j]=dp[j-1]+triangle[i][j];
                else
                dp[j]=min(dp[j]+triangle[i][j],dp[j-1]+triangle[i][j]);
            }
             dp[0]+=triangle[i][0];
        }
         int ans=INT_MAX;
         for(int i=0;i<n;i++)
         {
             ans=min(ans,dp[i]);
         }
         return ans;
    }
};