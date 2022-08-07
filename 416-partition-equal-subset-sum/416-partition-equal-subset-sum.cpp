class Solution {
public:
    // int dp[201][10000];
    // bool solve(int i,vector<int>& nums,int target)
    // {
    //     if(target==0)
    //         return true;
    //     if(target<0 || i==nums.size())
    //         return false;
    //     if(dp[i][target]!=0)
    //         return dp[i][target];
    //     dp[i][target]=solve(i+1,nums,target) || solve(i+1,nums,target-nums[i]);
    //     return dp[i][target];
    // }
    // bool canPartition(vector<int>& nums) {
    //     memset(dp,0,sizeof(dp));
    //     int sum=0;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //         sum+=nums[i];
    //     if(sum%2)
    //         return false;
    //     return solve(0,nums,sum/2);
    // }
    
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++)
//             sum+=nums[i];
//         if(sum%2)
//             return false;
//         int target=sum/2;
//         bool dp[n+1][target+1];
//         for(int i=0;i<=target;i++)
//             dp[0][i]=false;
//         for(int i=0;i<=n;i++)
//             dp[i][0]=true;
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=target;j++)
//             {
//                 dp[i][j]=dp[i-1][j];
//                 if(j>=nums[i-1])
//                     dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
//             }
//         }
//         return dp[n][target];
//     }
    
     bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        int target=sum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        
        for(int i=0;i<n;i++)
        {
            for(int j=target;j>=1;j--)
            {
                if(j>=nums[i])
                    dp[j]=dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};