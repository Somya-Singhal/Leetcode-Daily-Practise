class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int dp[numRows][2*numRows-1];
        vector<vector<int>>res;
        for(int i=0;i<numRows;i++)
        {
            vector<int>v;
            for(int j=numRows-i-1;j<=numRows+i-1;j+=2)
            {
                if(j==numRows-i-1 || j==numRows+i-1)
                {
                    dp[i][j]=1;
                    v.push_back(dp[i][j]);
                }
                else
                {
                   dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
                    v.push_back(dp[i][j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};