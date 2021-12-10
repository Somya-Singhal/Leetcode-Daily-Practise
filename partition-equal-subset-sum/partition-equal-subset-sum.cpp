class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
            return false;
        int val=sum/2;
        bool dp[n+1][val+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=val;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else
                {
                    if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][val];
    }
};