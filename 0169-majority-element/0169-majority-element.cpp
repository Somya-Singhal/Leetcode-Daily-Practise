class Solution {
public:
    int findele(vector<int>& nums)
    {
        int res=0,count=1;
        for(int i=1;i<nums.size();i++)
        {
           
            if(nums[i]==nums[res])
                count+=1;
            else
                count-=1;
            if(count==0)
            {
                res=i;
                count=1;
            }
        }
        return res;
    }
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int idx=findele(nums);
        int target=n/2;
        int ans=-1,count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[idx])
                count+=1;
        }
        return count>target?nums[idx]:-1;
    }
};