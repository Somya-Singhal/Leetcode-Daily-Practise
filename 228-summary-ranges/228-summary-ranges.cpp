class Solution {
public:
    
    // vector<string> summaryRanges(vector<int>& nums) {
    //     vector<string>res;
    //     int n=nums.size();
    //     if(n==0)
    //         return {};
    //     int prev=nums[0];
    //     for(int i=1;i<n;i++)
    //     {
    //         if(nums[i]==nums[i-1]+1)
    //             continue;
    //         else{
    //             string str="";
    //             if(prev==nums[i-1])
    //                 str=to_string(prev);
    //             else
    //             str=to_string(prev)+"-"+">"+to_string(nums[i-1]);
    //             res.push_back(str);
    //             prev=nums[i];
    //         }
    //     }
    //     if(prev==nums[n-1])
    //             res.push_back(to_string(nums[n-1]));
    //     else
    //     {
    //         string str=to_string(prev)+"-"+">"+to_string(nums[n-1]);
    //         res.push_back(str);
    //     }
    //     return res;
    // }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        if(n==1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            while(i<n-1 && nums[i]+1==nums[i+1])
            {
                i++;
                end++;
            }
            if(start==end)
                res.push_back(to_string(nums[start]));
            else
                res.push_back(to_string(nums[start])+"-"+">"+to_string(nums[end]));
            end++;
            start=end;
        }
        return res;
    }
};