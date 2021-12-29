class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<triangle[i].size();j++)
           {
               if(j==0)
                 triangle[i][j]+=triangle[i-1][0];
               else if(j==triangle[i].size()-1)
                   triangle[i][j]+=triangle[i-1][j-1];
               else
               {
                   int temp=triangle[i][j];
                   triangle[i][j]=min(temp+triangle[i-1][j-1],temp+triangle[i-1][j]);
               }
           }
       }
       int ans=triangle[n-1][0];
       for(int i=1;i<n;i++)
       {
           ans=min(ans,triangle[n-1][i]);
       }
        return ans;
    }
};