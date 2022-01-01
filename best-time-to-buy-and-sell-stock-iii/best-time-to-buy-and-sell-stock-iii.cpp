class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp1[n],dp2[n];
        int currmin=prices[0],currmax=prices[n-1];
        dp1[0]=0,dp2[n-1]=0;
        for(int i=1;i<n;i++)
        {
            currmin=min(currmin,prices[i]);
            dp1[i]=max(dp1[i-1],prices[i]-currmin);
        }
        for(int i=n-2;i>=0;i--)
        {
            currmax=max(currmax,prices[i]);
            dp2[i]=max(dp2[i+1],currmax-prices[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp1[i]+dp2[i]);
        }
        return ans;
    }
};