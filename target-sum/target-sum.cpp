class Solution {
public:
    int findtarget(int idx,vector<int>& nums, int target,int val)
    {
        if(val==target && idx==nums.size())
            return 1;
        if(val!=target && idx==nums.size())
            return 0;
        return findtarget(idx+1,nums,target,val+nums[idx])+findtarget(idx+1,nums,target,val-nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findtarget(0,nums,target,0);
    }
};