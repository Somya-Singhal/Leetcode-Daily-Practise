class Solution {
public:
    int mod=1e9+7;
    // int numOfWays(int n) {
    //     long a121=6,a123=6,b121,b123;
    //     for(int i=1;i<n;i++)
    //     {
    //         b121=3*a121+2*a123;
    //         b123=2*a121+2*a123;
    //         a121=b121%mod;
    //         a123=b123%mod;
    //     }
    //     return (a121+a123)%mod;
    // }
    
     int dfs(int n,int a0,int b0,int c0,vector<vector<vector<vector<int>>>>& dp,vector<int>& colors)
     {
         if(n==0)
             return 1;
         if(dp[n][a0][b0][c0]!=-1)
             return dp[n][a0][b0][c0];
         int ans=0;
         for(int a: colors)
         {
             if(a==a0)
                 continue;
             for(int b: colors)
             {
                 if(b==b0 || b==a)
                     continue;
                 for(int c: colors)
                 {
                     if(c==c0 || c==b)
                         continue;
                     ans+=dfs(n-1,a,b,c,dp,colors);
                     ans=ans%mod;
                 }
             }
         }
         return dp[n][a0][b0][c0]=ans;
     }
     int numOfWays(int n) {
        vector<vector<vector<vector<int>>>>dp=vector(n+1,vector(4,vector(4,vector(4,-1))));
         vector<int>colors{1,2,3};
        return dfs(n,0,0,0,dp,colors);
    }
};