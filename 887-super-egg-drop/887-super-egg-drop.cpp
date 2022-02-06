class Solution {
public:
    //recursive
    // int superEggDrop(int k, int n) {
    //     if(k==1 || n==0 || n==1)
    //         return n;
    //     int ans=INT_MAX;
    //     for(int i=1;i<=n;i++)
    //     {
    //         int temp=1+max(superEggDrop(k-1,i-1),superEggDrop(k,n-i));
    //         ans=min(ans,temp);
    //     }
    //     return ans;
    // }
    
    //dp
    //time-->O(k*n^2)
    // int superEggDrop(int k, int n) {
    //     int dp[k+1][n+1];
    //     for(int i=0;i<=n;i++)
    //         dp[1][i]=i;
    //     for(int i=0;i<=k;i++)
    //     {
    //         dp[i][0]=0;
    //         dp[i][1]=1;
    //     }
    //     for(int e=2;e<=k;e++)
    //     {
    //         for(int f=2;f<=n;f++)
    //         {
    //             dp[e][f]=INT_MAX;
    //             for(int x=1;x<=f;x++)
    //             {
    //                 int temp=1+max(dp[e-1][x-1],dp[e][f-x]);
    //                 dp[e][f]=min(dp[e][f],temp);
    //             }
    //         }
    //     }
    //     return dp[k][n];
    // }
    
    //binary search instead of linear search
    //time->O(k*nlogn)
    // int solve(int k,int n,vector<vector<int>>& dp)
    // {
    //      if(k==1)
    //        return n;
    //      if(n==0 || n==1)
    //          return n;
    //      if(dp[k][n]!=-1)
    //          return dp[k][n];
    //      int ans=INT_MAX,lo=1,hi=n;
    //      while(lo<=hi)
    //      {
    //          int mid=(lo+hi)/2;
    //          int left=solve(k-1,mid-1,dp);
    //          int right=solve(k,n-mid,dp);
    //          if(left<right)
    //              lo=mid+1;
    //          else
    //              hi=mid-1;
    //          int temp=1+max(left,right);
    //          ans=min(ans,temp);
    //      }
    //     return dp[k][n]=ans;
    // }
    //  int superEggDrop(int k, int n) {
    //    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    //      return solve(k,n,dp);
    // }
    
    //time->O((n*k)*logn)
     int superEggDrop(int k, int n) {
        int dp[k+1][n+1];
        for(int i=0;i<=n;i++)
            dp[1][i]=i;
        for(int i=0;i<=k;i++)
        {
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int e=2;e<=k;e++)
        {
            for(int f=2;f<=n;f++)
            {
                dp[e][f]=INT_MAX;
                int lo=1,hi=f;
                while(lo<=hi)
                {
                    int mid=(lo+hi)/2;
                    int left=dp[e-1][mid-1];
                    int right=dp[e][f-mid];
                    int temp=1+max(left,right);
                    if(left<right)
                        lo=mid+1;
                    else
                        hi=mid-1;
                    dp[e][f]=min(dp[e][f],temp);
                }
            }
        }
        return dp[k][n];
    }
};