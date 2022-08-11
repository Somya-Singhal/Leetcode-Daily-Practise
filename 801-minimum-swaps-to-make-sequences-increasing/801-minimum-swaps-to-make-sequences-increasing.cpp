class Solution {
public:
    // int solve(int i,int prevA,int prevB,vector<int>& nums1, vector<int>& nums2,int swapped,vector<vector<int>>& dp)
    // {
    //     int n=nums1.size();
    //     if(i==n)
    //         return 0;
    //     if(dp[i][swapped]!=-1)
    //         return dp[i][swapped];
    //     int minSwaps=INT_MAX;
    //     if(nums1[i]>prevA && nums2[i]>prevB)
    //     {
    //         minSwaps=solve(i+1,nums1[i],nums2[i],nums1,nums2,0,dp);
    //     }
    //     // swap(nums1[i],nums2[i]);
    //     if(nums2[i]>prevA && nums1[i]>prevB)
    //     {
    //         minSwaps=min(minSwaps,solve(i+1,nums2[i],nums1[i],nums1,nums2,1,dp)+1);
    //     }
    //     // swap(nums1[i],nums2[i]);
    //     return dp[i][swapped]=minSwaps;
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     int n=nums1.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,-1));
    //     return solve(0,-1,-1,nums1,nums2,0,dp);
    // }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>swapped(n,1),notSwapped(n,0);
        for(int i=1;i<n;i++)
        {
            swapped[i]=notSwapped[i]=n;
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i])
            {
                swapped[i]=swapped[i-1]+1;
                notSwapped[i]=notSwapped[i-1];
            }
            if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i])
            {
                swapped[i]=min(swapped[i],notSwapped[i-1]+1);
                notSwapped[i]=min(notSwapped[i],swapped[i-1]);
            }
        }
        return min(swapped[n-1],notSwapped[n-1]);
    }
};