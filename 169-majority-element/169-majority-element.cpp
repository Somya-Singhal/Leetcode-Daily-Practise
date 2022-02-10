class Solution {
public:
    int mooreVoting(vector<int>& nums)
    {
        int res=0,count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[res])
                count++;
            else
            count--;
            if(count==0)
            {
                count=1;
                res=i;
            }
        }
        return res;
    }
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=mooreVoting(nums);
        int count=0;
        // for(int j=0;j<n;j++)
        // {
        //     if(nums[j]==nums[i])
        //         count++;
        // }
        return nums[i];
    }
};