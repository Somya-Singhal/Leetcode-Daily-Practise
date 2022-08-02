class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int largest=0;
        vector<vector<int>>dp(row,vector<int>(col));
        for(int i=0;i<row;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            largest=max(largest,dp[i][0]);
        }
            
        for(int j=0;j<col;j++)
        {
            dp[0][j]=matrix[0][j]-'0';
            largest=max(largest,dp[0][j]);
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                    largest=max(largest,dp[i][j]);
                }
            }
        }
        return largest*largest;
    }
};