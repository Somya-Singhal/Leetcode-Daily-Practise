class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        int pre=0;
        for(int i=0;i<n;i++)
        {
            pre+=nums[i];
            res.push_back(pre);
            
        }
        return res;
    }
};