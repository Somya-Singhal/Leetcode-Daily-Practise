class Solution {
public:
//     long long ans=INT_MIN;
//     int maxprod(int idx,int n,int sum,long long curr)
//     {
//         if(sum==n)
//         {
//              ans=max(ans,curr);
//             return;
//         }
//         if(idx>=n || sum>n)
//             return;
    
//      maxprod(idx,n,sum+idx,curr*idx);
//      maxprod(idx+1,n,sum,curr);
//      return;
//     }
    // int integerBreak(int n) {
    //     maxprod(1,n,0,1);
    //     return ans;
    // }
    int num;
 int solve(int n,vector<int>& dp)
 {
     if(dp[n]!=-1)
         return dp[n];
     if(n==num)
         dp[n]=0;
     else
         dp[n]=n;
     for(int i=1;i<n;i++)
     {
         int val=solve(i,dp)*solve(n-i,dp);
         dp[n]=max(dp[n],val);
     }
     return dp[n];
 }
 int integerBreak(int n) {
     vector<int>dp(n+1,-1);
     dp[1]=1;
     num=n;
    return solve(n,dp);
    }
};