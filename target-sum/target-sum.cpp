class Solution {
public:
    
    // recursive
    //  int findtarget(int idx,vector<int>& nums, int target,int val)
    // {
    //     if(val==target && idx==nums.size())
    //         return 1;
    //     if(val!=target && idx==nums.size())
    //         return 0;
    //     return findtarget(idx+1,nums,target,val+nums[idx])+findtarget(idx+1,nums,target,val-nums[idx]);
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return findtarget(0,nums,target,0);
    // }
    
    // dp
    // suppose: s1(subset of nums) and s2(remaining) are two subsets where s1 only contains element with +ve sign and s2 conatins element with -ve sign then,
    // s1-s2=target
    // s1+s2=sum    (of whole vector)
    // ----------
    // 2s1  =(target+sum)   
    // ----------
    // s1=(target+sum)/2
    // Now it became count of subset sum with target as (target+sum)/2
    // int countsubsetsum(int idx,vector<int>& nums, int val)
    // {
    //     int n=nums.size();
    //     int dp[n+1][val+1];
    //     for(int i=0;i<=n;i++)
    //     {
    //         for(int j=0;j<=val;j++)
    //         {
    //             if(i==0)
    //                 dp[i][j]=0;
    //             if(j==0)
    //                 dp[i][j]=1;
    //         }
    //     }
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=0;j<=val;j++)
    //         {
    //             if(nums[i-1]<=j)
    //                 dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
    //             else
    //                 dp[i][j]=dp[i-1][j];
    //         }
    //     }
    //     return dp[n][val];
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         sum+=nums[i];
    //     }
    //     if((target+sum)%2!=0 || target>sum)
    //         return 0;
    //     int val=(target+sum)/2;
    //    return countsubsetsum(0,nums,val);
    // }
    int countsubsetsum(int idx,vector<int>& nums, int val)
    {
        int n=nums.size();
        int dp[n+1][val+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=val;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=val;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][val];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if((target+sum)%2!=0 || target>sum)
            return 0;
        int val=(target+sum)/2;
       return countsubsetsum(0,nums,val);
    }
       
       
};
