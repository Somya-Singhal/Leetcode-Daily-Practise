class Solution {
public:
    // int totalWays(vector<int>& nums,int target,unordered_map<int,int>& m)
    // {
    //     if(target==0)
    //     {
    //         return 1;
    //     }
    //     if(target<0)
    //         return 0;
    //     if(m.find(target)!=m.end())
    //     {
    //         return m[target];
    //     }
    //     int count=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]>target)
    //             break;
    //         count+=totalWays(nums,target-nums[i],m);
    //     }
    //     return m[target]=count;
    // }
    // int combinationSum4(vector<int>& nums, int target) {
    //     sort(nums.begin(),nums.end());
    //     unordered_map<int,int>m;
    //     return totalWays(nums,target,m);
    // }
    
    //  int totalWays(vector<int>& nums,int target,vector<int>& dp)
    //  {
    //      if(target==0)
    //          return 1;
    //      if(dp[target]!=-1)
    //          return dp[target];
    //      int count=0;
    //      for(int i=0;i<nums.size();i++)
    //      {
    //          if(nums[i]<=target)
    //           count+=totalWays(nums,target-nums[i],dp);
    //      }
    //     return dp[target]=count;
    //  }
    //  int combinationSum4(vector<int>& nums, int target) {
    //     vector<int>dp(target+1,-1);
    //     dp[0]=1; 
    //     return totalWays(nums,target,dp);
    // }
    
    
     int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long>dp(target+1,0);
        dp[0]=1; 
         if(target==0)
             return 1;
         for(int i=1;i<=target;i++)
         {
             for(int j=0;j<nums.size();j++)
             {
                if(i>=nums[j])
                dp[i]+=dp[i-nums[j]];
             }
         }
        return dp[target];
    }
};