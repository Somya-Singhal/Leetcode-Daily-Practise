class Solution {
public:
    void reverse(int lo,int hi,vector<vector<int>>& grid){
        int m=grid[0].size();
        while(lo<hi){
            int r=lo/m,c=lo++%m,i=hi/m,j=hi--%m;
            int temp=grid[r][c];
            grid[r][c]=grid[i][j];
            grid[i][j]=temp;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // int n=grid.size(),m=grid[0].size();
        // if(k==0)
        //     return grid;
        // vector<vector<int>>ans(n,vector<int>(m,0));
        // for(int t=0;t<k;t++){
        //   for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i==n-1 && j==m-1)
        //             ans[0][0]=grid[i][j];
        //         else if(j==m-1)
        //             ans[i+1][0]=grid[i][j];
        //         else
        //             ans[i][j+1]=grid[i][j];
        //     }
        // } 
        // grid=ans;
        // }
        // return ans;
        int n=grid.size(),m=grid[0].size();
        k%=m*n;
        vector<vector<int>>ans(n,vector<int>(m,0));
        reverse(0,n*m-1,grid);
        reverse(0,k-1,grid);
        reverse(k,n*m-1,grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=grid[i][j];
            }
        }
        return ans;
    }
};