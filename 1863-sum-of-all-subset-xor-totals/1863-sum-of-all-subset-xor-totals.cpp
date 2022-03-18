class Solution {
public:
    int solve(int i,int curr,vector<int>& nums)
    {
        if(i==nums.size())
        return curr;
        return solve(i+1,curr^nums[i],nums)+solve(i+1,curr,nums);
    }
    int subsetXORSum(vector<int>& nums) {
       return solve(0,0,nums); 
    }
};