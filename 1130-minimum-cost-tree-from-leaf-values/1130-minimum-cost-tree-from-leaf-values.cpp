class Solution {
public:
    //recursion
    int solve(int s,int e,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(dp[s][e]!=0)
            return dp[s][e];
        if(s>=e)
            return 0;
        int res=INT_MAX;
        for(int i=s;i<e;i++)
        {
            int maxx=INT_MIN,maxy=INT_MIN;
            for(int t=s;t<=i;t++)
                maxx=max(maxx,arr[t]);
            for(int t=i+1;t<=e;t++)
                maxy=max(maxy,arr[t]);
            // cout<<maxx<<" "<<maxy<<endl;
           res=min(res,maxx*maxy+solve(s,i,arr,dp)+solve(i+1,e,arr,dp)); 
        }
      return dp[s][e]=res;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return solve(0,n-1,arr,dp);
    }
    
    //top-down: time:O(n^4), space:O(n^2)
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     for(int gap=0;gap<n;gap++)
    //     {
    //         for(int i=0,j=gap;j<n;i++,j++)
    //         {
    //             if(j==i+1)
    //                 dp[i][j]=arr[i]*arr[j];
    //             else
    //             {
    //                 int ans=INT_MAX;
    //                 for(int k=i;k<j;k++)
    //                 {
    //                     int maxx=INT_MIN,maxy=INT_MIN;
    //                     for(int t=i;t<=k;t++)
    //                     {
    //                         maxx=max(maxx,arr[t]);
    //                     }  
    //                     for(int t=k+1;t<=j;t++)
    //                     {
    //                         maxy=max(maxy,arr[t]);
    //                     }
    //                     // cout<<maxx*maxy+dp[i][k]+dp[k+1][j]<<endl;
    //                     ans=min(ans,maxx*maxy+dp[i][k]+dp[k+1][j]);
    //                     dp[i][j]=ans;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][n-1];
    // }
};