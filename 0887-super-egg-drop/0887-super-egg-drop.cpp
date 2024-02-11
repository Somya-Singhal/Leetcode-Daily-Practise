class Solution {
public:
    // int solve(int k,int n,vector<vector<int>>& temp){
    //     if(n==0 || n==1)
    //         return n;
    //     if(k==1){
    //         return n;
    //     }
    //     if(temp[k][n]!=-1){
    //         return temp[k][n];
    //     }
    //     int ans=INT_MAX;
    //     for(int j=1;j<=n;j++){
    //         int hi=INT_MAX,lo=INT_MAX;
    //         if(temp[k-1][j-1]!=-1){
    //             hi=temp[k-1][j-1];
    //         } else {
    //             hi=solve(k-1,j-1,temp);
    //         }
    //         if(temp[k][n-j]!=-1){
    //             lo=temp[k][n-j];
    //         } else {
    //             lo=solve(k,n-j,temp);
    //         }
    //         int num=1+ max(hi,lo);
    //         ans=min(ans,num);
    //     }
    //     return temp[k][n]=ans;
    // }
    int superEggDrop(int k, int n) {
        vector<vector<int>>temp(k+1,vector<int>(n+1,-1));
        for(int i=0;i<=k;i++){
            temp[i][0]=0;
            temp[i][1]=1;
        }
        for(int i=0;i<=n;i++){
            temp[1][i]=i;
        }
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                temp[i][j]=INT_MAX;
                int lo=2,hi=j;
                while(lo<=hi){
                    int mid=(lo+hi)/2;
                    int left=temp[i-1][mid-1];
                    int right=temp[i][j-mid];
                    if(left<right)
                        lo=mid+1;
                    else{
                        hi=mid-1;
                    }
                    int ans=1+max(left,right);
                    temp[i][j]=min(temp[i][j],ans);
                }
            }
        }
        return temp[k][n];
    }
    
//     int superEggDrop(int k, int n) {
//         int dp[k+1][n+1];
//         for(int i=0;i<=n;i++)
//             dp[1][i]=i;
//         for(int i=0;i<=k;i++)
//         {
//             dp[i][0]=0;
//             dp[i][1]=1;
//         }
//         for(int e=2;e<=k;e++)
//         {
//             for(int f=2;f<=n;f++)
//             {
//                 dp[e][f]=INT_MAX;
//                 int lo=1,hi=f;
//                 while(lo<=hi)
//                 {
//                     int mid=(lo+hi)/2;
//                     int left=dp[e-1][mid-1];
//                     int right=dp[e][f-mid];
//                     int temp=1+max(left,right);
//                     if(left<right)
//                         lo=mid+1;
//                     else
//                         hi=mid-1;
//                     dp[e][f]=min(dp[e][f],temp);
//                 }
//             }
//         }
//         return dp[k][n];
//     }
};