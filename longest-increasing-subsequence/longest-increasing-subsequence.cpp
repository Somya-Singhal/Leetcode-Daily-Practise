class Solution {
public:
    //recursive
//     int LISrec(vector<int>& nums,int n,int *ans)
//     {
//        if(n==1)
//             return 1;
//         int res,max_ending=1;
//        for(int i=1;i<n;i++)
//        {
//            res=LISrec(nums,i,ans);
//            if(nums[i-1]<nums[n-1] && res+1>max_ending)
//                max_ending=res+1;
//        }
//         if(*ans<max_ending)
//             *ans=max_ending;
        
//         return max_ending;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int ans=1;
//        LISrec(nums,n,&ans);
//         return ans;
//     }
    
    //dp
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int dp[n];
//         dp[0]=1;
//         int ans=1;
//         for(int i=1;i<n;i++)
//         {
//             dp[i]=1;
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(nums[i]>nums[j])
//                     dp[i]=max(dp[i],dp[j]+1);
//             }
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
    //binary search-->O(nlogn)
    int CeilIndex(vector<int>& tail,int l,int r,int key)
    {
        while(r-l>1)
        {
            int mid=l+(r-l)/2;
            if(tail[mid]>=key)
                r=mid;
            else
                l=mid;
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>tail(n,0);
        tail[0]=nums[0];
        int length=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<tail[0])
                tail[0]=nums[i];
            else if(nums[i]>tail[length-1])
                tail[length++]=nums[i];
            else
                tail[CeilIndex(tail,-1,length-1,nums[i])]=nums[i];
        }
        return length;
    }
};
