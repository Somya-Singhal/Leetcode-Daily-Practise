class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                dp[i][j]=0;
                else
                dp[i][j]=1;    
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]!=0)
                dp[i][j]+=dp[i-1][j];    
            }
        }
        for(int i=0;i<n;i++)
        {
            stack<int>s;
            for(int j=0;j<m;j++)
            {
                while(!s.empty() && dp[i][s.top()]>=dp[i][j])
                {
                    int top=s.top();
                    s.pop();
                    int dist=s.empty()?j:j-s.top()-1;
                    int curr_area=(dp[i][top])*dist;
                    maxArea=max(maxArea,curr_area); 
                }
                s.push(j);
            }
            while(!s.empty())
            {
                    int top=s.top();
                    s.pop();
                    int dist=s.empty()?m:m-s.top()-1;
                    int curr_area=(dp[i][top])*dist;
                    maxArea=max(maxArea,curr_area); 
            }
        }
        return maxArea;
    }
};