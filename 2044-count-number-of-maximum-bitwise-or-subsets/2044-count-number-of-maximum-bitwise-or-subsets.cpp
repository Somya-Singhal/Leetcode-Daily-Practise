class Solution {
public:
    int tmax=0,count=0;
    void totalSubsets(int idx,int curr,vector<int>& nums)
    {
        if(idx==nums.size())
        {
            if(curr==tmax)
            {
                count++;
            }
            if(curr>tmax)
            {
                count=1;
                tmax=curr;
            } 
            return;
        }
        
            totalSubsets(idx+1,curr|nums[idx],nums);
            totalSubsets(idx+1,curr,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        totalSubsets(0,0,nums);
        return count;
    }
};