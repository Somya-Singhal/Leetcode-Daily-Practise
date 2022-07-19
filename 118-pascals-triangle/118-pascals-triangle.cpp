class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows,vector<int>(2*numRows-1));
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
    //  vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>>res(numRows);
    //     for(int i=0;i<numRows;i++)
    //     {
    //         res[i].resize(i+1);
    //         res[i][0]=res[i][i]=1;
    //         for(int j=1;j<i;j++)
    //         {
    //             res[i][j]=res[i-1][j-1]+res[i-1][j];
    //         }
    //     }
    //     return res;
    // }
};