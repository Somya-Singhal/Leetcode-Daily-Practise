class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //    for(int i=1;i<n;i++)
    //    {
    //        for(int j=0;j<triangle[i].size();j++)
    //        {
    //            if(j==0)
    //              triangle[i][j]+=triangle[i-1][0];
    //            else if(j==triangle[i].size()-1)
    //                triangle[i][j]+=triangle[i-1][j-1];
    //            else
    //            {
    //                int temp=triangle[i][j];
    //                triangle[i][j]=min(temp+triangle[i-1][j-1],temp+triangle[i-1][j]);
    //            }
    //        }
    //    }
    //    int ans=triangle[n-1][0];
    //    for(int i=1;i<n;i++)
    //    {
    //        ans=min(ans,triangle[n-1][i]);
    //    }
    //     return ans;
    // }
     int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>pre(m,triangle[0][0]);
        vector<int>curr(m,0);
        for(int i=1;i<m;i++)
        {
            int n=triangle[i].size();
            curr[n-1]=pre[n-2]+triangle[i][n-1];
            curr[0]=pre[0]+triangle[i][0];
            
            for(int j=1;j<=n-2;j++)
            {
                curr[j]=min(pre[j-1],pre[j])+triangle[i][j];
            }
            pre=curr;
        }
         int ans=INT_MAX;
         for(int i=0;i<m;i++)
         {
             // cout<<curr[i]<<" ";
             ans=min(ans,pre[i]);
         }
         return ans;
    }
};