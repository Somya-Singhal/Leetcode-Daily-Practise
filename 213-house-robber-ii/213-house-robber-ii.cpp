class Solution {
public:
    //recursion
    // int robbery(int s,int e,vector<int>& nums)
    // {
    //     if(s==e)
    //         return nums[s];
    //     if(s>e)
    //         return 0;
    //     return max(nums[s]+robbery(s+2,e,nums),robbery(s+1,e,nums));
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     return max(nums[0]+robbery(2,n-2,nums),robbery(1,n-1,nums));
    // }
    
    //dp
    int robbery(int s,int e,vector<int>& nums)
    {
        int second=0,first=0;
        for(int i=e;i>=s;i--)
        {
           int curr=max(nums[i]+second,first);
            second=first;
            first=curr;
        }
        return first;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        return max(robbery(0,n-2,nums),robbery(1,n-1,nums));
    }
};