class Solution {
public:
    // brute force
    // int maxProduct(vector<int>& nums) {
    //     int max_prod=INT_MIN;
    //   for(int i=0;i<nums.size();i++)
    //   {
    //       int curr_prod=1;
    //       for(int j=i;j<nums.size();j++)
    //       {
    //           curr_prod*=nums[j];
    //           max_prod=max(max_prod,curr_prod);
    //       }
    //   }
    //     return max_prod;
    // }
    int maxProduct(vector<int>& nums) {
       int curr_max=nums[0];
        int curr_min=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(curr_min,curr_max);
            curr_min=min(nums[i],curr_min*nums[i]);
            curr_max=max(nums[i],curr_max*nums[i]);
            ans=max(ans,curr_max);
        }
        return ans;
    }
};