class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int i,vector<int>& nums,int target)
    {
        int n=nums.size();
        if(i==n)
            return target==0;
       string str=to_string(i)+" "+to_string(target);
       if(mp.find(str)!=mp.end())
           return mp[str];
        mp[str]=solve(i+1,nums,target+nums[i])+solve(i+1,nums,target-nums[i]);
        return mp[str];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>>memo(n+1,vector<int>(1001,-1));
        return solve(0,nums,target);
    }
};