class Solution {
public:
    // int solve(vector<int>& nums, int target,vector<int>& memo)
    // {
    //     if(target==0)
    //         return 1;
    //     if(target<0)
    //         return 0;
    //     if(memo[target]!=-1)
    //         return memo[target];
    //     int ways=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         ways+=solve(nums,target-nums[i],memo);
    //     }
    //     memo[target]=ways;
    //     return memo[target];
    // }
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<int>memo(target+1,-1);
    //     return solve(nums,target,memo);
    // }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>memo(target+1,0);
        memo[0]=1;
        for(int i=1;i<=target;i++)
        {
            long ways=0;
            for(int j=0;j<nums.size();j++)
            {
                if(i>=nums[j])
                     ways+=memo[i-nums[j]]; 
            }
            memo[i]=ways;  
        }
            
        return memo[target];
    }
};