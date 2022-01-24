class Solution {
public:
    //time:O(nk), space:O(n)
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     vector<int>dp(n+1,0);
    //     for(int i=1;i<=n;i++)
    //     {
    //         int maxarr=0,best=0;
    //         for(int j=1;(i-j)>=0 && j<=k;j++)
    //         {
    //             maxarr=max(maxarr,arr[i-j]);
    //             best=max(best,dp[i-j]+maxarr*j);
    //         }
    //         dp[i]=best;
    //     }
    //     return dp[n];
    // }
    
     int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(k);
        for(int i=1;i<=n;i++)
        {
            int best=0,currmax=0;
            for(int j=1;(i-j)>=0 && j<=k;j++)
            {
                currmax=max(currmax,arr[i-j]);
                best=max(best,dp[(i-j)%k]+currmax*j);
            }
            dp[i%k]=best;
        }
        return dp[n%k];
    }
};