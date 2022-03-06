class Solution {
public:
    // long long cache[501][501]={0};
    // int mod=1e9+7;
    // long long solve(int unpicked,int undelivered)
    // {
    //     if(unpicked==0 && undelivered==0)
    //         return 1;
    //     if(unpicked>undelivered || undelivered<0 || unpicked<0)
    //         return 0;
    //     if(cache[unpicked][undelivered]!=0)
    //         return cache[unpicked][undelivered];
    //     long long pickways=unpicked*solve(unpicked-1,undelivered)%mod;
    //     long long deliveredways=(undelivered-unpicked)*solve(unpicked,undelivered-1)%mod;
    //     return cache[unpicked][undelivered]=pickways+deliveredways;
    // }
    // int countOrders(int n) {
    //    return solve(n,n); 
    // }
    
    
     int mod=1e9+7;
     int countOrders(int n) {
      vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));
         for(int unpicked=0;unpicked<=n;unpicked++)
         {
             for(int undelivered=0;undelivered<=n;undelivered++)
             {
                 if(unpicked==0 && undelivered==0)
                 {
                     dp[unpicked][undelivered]=1;
                     continue;
                 }
                 if(unpicked>0)
                    dp[unpicked][undelivered]+=unpicked*dp[unpicked-1][undelivered]%mod;
                 if(undelivered>unpicked)
                 dp[unpicked][undelivered]+=(undelivered-unpicked)*dp[unpicked][undelivered-1]%mod;
             }
         }
         return dp[n][n];
    }
};