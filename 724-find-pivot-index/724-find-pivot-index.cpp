class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right=0,left=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            right+=nums[i];
        
        for(int i=0;i<n;i++)
        {
            right-=nums[i];
            if(left==right)
                return i;
            left+=nums[i];
        }
        return -1;
    }
};