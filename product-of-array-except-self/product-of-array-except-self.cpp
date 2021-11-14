class Solution {
public:
    //beauty->use suffix and prefix array
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pre_product[n],pre_suffix[n];
        pre_product[0]=nums[0];
        pre_suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pre_product[i]=pre_product[i-1]*nums[i];
        for(int i=n-2;i>=0;i--)
            pre_suffix[i]=pre_suffix[i+1]*nums[i];
        for(int i=0;i<n;i++)
        {
            ans[i]=((i>=1)?pre_product[i-1]:1)*((i<n-1)?pre_suffix[i+1]:1);
        }
        return ans;
    }
};