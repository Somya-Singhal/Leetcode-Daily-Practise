class Solution {
public:
    //recursive
    // int robrec(int idx,vector<int>& nums)
    // {
    //     if(idx>=nums.size())
    //         return 0;
    //     return max(nums[idx]+robrec(idx+2,nums),robrec(idx+1,nums));    
    // }
    // int rob(vector<int>& nums) {
    //     return robrec(0,nums);
    // }
        
    // dp
    int rob(vector<int>& nums) {
        int dp[nums.size()+2];
        dp[0]=0,dp[1]=0;
        for(int i=2;i<=nums.size()+1;i++)
        {
            dp[i]=max(nums[i-2]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()+1];
    }
};