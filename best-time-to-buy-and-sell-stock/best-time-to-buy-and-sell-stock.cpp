class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curr_min=prices[0];
        int res=0;
        for(int i=1;i<n;i++)
        {
            curr_min=min(curr_min,prices[i]);
            res=max(res,prices[i]-curr_min);
        }
        return res;
    }
};