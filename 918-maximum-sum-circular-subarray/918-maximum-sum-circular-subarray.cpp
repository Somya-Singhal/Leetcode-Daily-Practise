class Solution {
public:
    int kadanesAlgo(vector<int>& nums)
    {
        int currmax=nums[0],totalmax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            currmax=max(nums[i],currmax+nums[i]);
            totalmax=max(totalmax,currmax);
        }
        return totalmax;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,n=nums.size();
        int normalmax=kadanesAlgo(nums);
        if(normalmax<0)
            return normalmax;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int circularmax=kadanesAlgo(nums);
        int currmax=sum+circularmax;
        return max(normalmax,currmax);
    }
};