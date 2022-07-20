class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>pre(n,matrix[0][0]),curr(n,0);
        for(int i=1;i<n;i++)
            pre[i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            curr[0]=min(pre[0],pre[1])+matrix[i][0];
            curr[n-1]=min(pre[n-1],pre[n-2])+matrix[i][n-1];
            for(int j=1;j<=n-2;j++)
                curr[j]=min(min(pre[j-1],pre[j]),pre[j+1])+matrix[i][j];
            pre=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,pre[i]);
        return ans;
    }
};