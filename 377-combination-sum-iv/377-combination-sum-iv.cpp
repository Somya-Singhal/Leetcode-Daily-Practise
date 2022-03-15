class Solution {
public:
    int totalWays(vector<int>& nums,int target,unordered_map<int,int>& m)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0)
            return 0;
        if(m.find(target)!=m.end())
        {
            return m[target];
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>target)
                break;
            count+=totalWays(nums,target-nums[i],m);
        }
        return m[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        return totalWays(nums,target,m);
    }
};