class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,top=0,bottom=n-1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        int count=1;
        while(left<=right && top<=bottom){
            for(int l=left;l<=right;l++){
                ans[top][l]=count;
                count++;
            }
            top++;
            for(int t=top;t<=bottom;t++){
                ans[t][right]=count;
                count++;
            }
            right--;
            for(int r=right;r>=left;r--){
                ans[bottom][r]=count;
                count++;
            }
            bottom--;
            for(int b=bottom;b>=top;b--){
               ans[b][left]=count;
                count++;
            }
            left++;
        }
        return ans;
    }
};