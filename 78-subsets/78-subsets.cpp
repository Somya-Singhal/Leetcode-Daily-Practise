class Solution {
public:
    // void subsetrec(vector<vector<int>>& res,int index,vector<int>& temp,vector<int>& nums)
    // {
    //     if(index==nums.size())
    //      return;
    //     else
    //     {
    //         temp.push_back(nums[index]);
    //         res.push_back(temp);
    //         subsetrec(res,index+1,temp,nums);
    //         temp.pop_back();
    //         subsetrec(res,index+1,temp,nums);
    //     }
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>>res;
    //     vector<int>temp;
    //     res.push_back({});
    //     subsetrec(res,0,temp,nums);
    //     return res;
    // }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        int total=1<<n;
        for(int i=0;i<=total-1;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if((i>>j) & 1)
                  temp.push_back(nums[j]);  
            }
            res.push_back(temp);
        }
        return res;
    }
};