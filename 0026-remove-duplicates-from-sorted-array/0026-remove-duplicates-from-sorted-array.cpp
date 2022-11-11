class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int k=nums.size();
        if(k==0)
            return 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=200;
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};