class Solution {
public:
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        if(n==0)
            return {};
        int prev=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                continue;
            else{
                string str="";
                if(prev==nums[i-1])
                    str=to_string(prev);
                else
                str=to_string(prev)+"-"+">"+to_string(nums[i-1]);
                res.push_back(str);
                prev=nums[i];
            }
        }
        if(prev==nums[n-1])
                res.push_back(to_string(nums[n-1]));
        else
        {
            string str=to_string(prev)+"-"+">"+to_string(nums[n-1]);
            res.push_back(str);
        }
        return res;
    }
};