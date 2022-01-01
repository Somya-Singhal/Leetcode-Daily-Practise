class Solution {
public:
    // int Coinsrec(int i,vector<int>& nums,int ans)
    // {
    //     cout<<ans<<"\n";
    //     if(nums.size()==0)
    //         return ans;
    //     if(i==nums.size() && nums.size()>0)
    //         return 0;
    //     int temp;
    //     if(i==0)
    //     temp=1*nums[i]*nums[i+1];
    //     else if(i==nums.size()-1)
    //         temp=nums[i-1]*nums[i]*1;
    //     else
    //         temp=nums[i-1]*nums[i]*nums[i+1];
    //     int left=Coinsrec(i+1,nums,ans);
    //     nums.erase(nums.begin()+i);
    //     int right=Coinsrec(i,nums,ans+temp);
    //     return max(left,right);
    // }
    int maxCoins(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                    int currmax=INT_MIN;
                    for(int k=i;k<=j;k++)
                    {
                        int left=(k==i)?0:dp[i][k-1];
                        int right=(k==j)?0:dp[k+1][j];
                        int val=((i==0)?1:nums[i-1])*nums[k]*((j==n-1)?1:nums[j+1]);
                        int total=left+right+val;
                        currmax=max(total,currmax);
                        // cout<<currmax<<" ";
                    }
                    dp[i][j]=currmax;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][n-1];
    }
};