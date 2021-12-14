class Solution {
public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         int maxside_len=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]=='1')
//                 {
//                     int side_len=1;
//                     bool flag=true;
//                     while(side_len+i<n && side_len+j<m && flag)
//                     {
//                         for(int k=j;k<=side_len+j;k++)
//                         {
//                             if(matrix[i+side_len][k]=='0')
//                             {
//                                 flag=false;
//                                 break;
//                             }
//                         }
//                         for(int k=i;k<=side_len+i;k++)
//                         {
//                             if(matrix[k][j+side_len]=='0')
//                             {
//                                 flag=false;
//                                 break;
//                             }
//                         }
//                         if(flag)
//                             side_len++;
//                     }
//                     if(maxside_len<side_len)
//                             maxside_len=side_len;
//                 }
//             }
//         }
//         return maxside_len*maxside_len;
//     }
//     dp-->O(n*m)
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         int ans=0;
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
                
//                 if(matrix[i-1][j-1]=='1')
//                 {
//                     dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
//                     ans=max(ans,dp[i][j]);
//                 }  
//             }
//         }
//         return ans*ans;
//     }
    //     dp-->space-O(m)
     int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
         vector<int>dp(m+1,0);
        int prev=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int temp=dp[j];
                if(matrix[i-1][j-1]=='1')
                {
                    dp[j]=min(min(dp[j],dp[j-1]),prev)+1;
                    ans=max(ans,dp[j]);
                } 
                else
                    dp[j]=0;
                prev=temp;
            }
        }
        return ans*ans;
    }
};
