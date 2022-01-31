class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size(),m=accounts[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int currMoney=0;
            for(int j=0;j<m;j++)
            {
                currMoney+=accounts[i][j];
            }
            ans=max(ans,currMoney);
        }
        return ans;
    }
};