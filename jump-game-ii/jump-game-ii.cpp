class Solution {
public:
    //recursive
    // int jumprec(int idx,vector<int>& nums)
    // {
    //     if(idx>=nums.size())
    //         return INT_MAX-1;
    //     if(idx==nums.size()-1)
    //         return 0;
    //     int ans=INT_MAX-1;
    //     for(int i=1;i<=nums[idx];i++)
    //     {
    //         int len=1+jumprec(idx+i,nums);
    //         ans=min(ans,len);
    //     }
    //     return ans;
    // }
    
    //dp
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=INT_MAX-1;
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<n)
                dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0];
    }
};