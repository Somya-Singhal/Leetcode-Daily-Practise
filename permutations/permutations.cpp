class Solution {
public:
    // backtracking solution will work for many other problems
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_set<int>s;
        vector<int>temp;
        permuterec(res,s,temp,nums); 
        return res;
        }
    void permuterec(vector<vector<int>>& res,unordered_set<int>& s,vector<int>& temp,vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
        }
            for(int i=0;i<nums.size();i++)
            {
                if(s.find(nums[i])!=s.end())
                {
                 continue;   
                }
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                permuterec(res,s,temp,nums);
                auto it=s.find(temp[temp.size()-1]);
                if(it!=s.end())s.erase(it);
                temp.pop_back();
            }
        }
};