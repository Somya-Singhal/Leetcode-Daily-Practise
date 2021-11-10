class Solution {
public:
    void subsetrec(vector<vector<int>>& res,int index,vector<int>& temp,vector<int>& nums)
    {
        if(index==nums.size())
         return;
        else
        {
           temp.push_back(nums[index]);
            res.push_back(temp);
            subsetrec(res,index+1,temp,nums);
            temp.pop_back();
            subsetrec(res,index+1,temp,nums);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        res.push_back({});
        subsetrec(res,0,temp,nums);
        return res;
    }
};