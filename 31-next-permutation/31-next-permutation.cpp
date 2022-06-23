class Solution {
public:
    void reverse(vector<int>& nums,int i)
    {
        int s=i,e=nums.size()-1;
        while(i<e)
        {
            swap(nums[i],nums[e]);
            i++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i>=0)
        {
            int j=n-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums[j],nums[i]);
           
        }
         reverse(nums,i+1);
    }
};