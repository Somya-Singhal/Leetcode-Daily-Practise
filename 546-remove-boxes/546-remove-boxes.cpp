class Solution {
public:
    // int dp[101][101][101];
    // int solve(int l,int r,int count,vector<int>& boxes)
    // {
    //     if(l>r)
    //         return 0;
    //     if(dp[l][r][count]!=0)
    //         return dp[l][r][count];
    //     int l1=l,count1=count;
    //     while(l+1<=r && boxes[l]==boxes[l+1])
    //     {
    //         count+=1;
    //         l+=1;
    //     }
    //    int ans=(count+1)*(count+1)+solve(l+1,r,0,boxes);
    //     for(int k=l+1;k<=r;k++)
    //     {
    //         if(boxes[k]==boxes[l])
    //             ans=max(ans,solve(k,r,count+1,boxes)+solve(l+1,k-1,0,boxes));
    //     }
    //     dp[l1][r][count1]=ans;   
    //     return dp[l1][r][count1];
    // }
    // int removeBoxes(vector<int>& boxes) {
    //     int n=boxes.size();
    //     memset(dp,0,sizeof(dp));
    //     return solve(0,n-1,0,boxes);
    // }
    
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int dp[101][101][101];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<=i;k++)
                dp[i][i][k]=(k+1)*(k+1);
        }
        for(int l=1;l<n;l++)
        {
            for(int j=l;j<n;j++)
            {
               int i=j-l;   
                for(int count=0;count<=i;count++)
                {
                   int ans=(count+1)*(count+1)+dp[i+1][j][0];
                    for(int k=i+1;k<=j;k++)
                    {
                        if(boxes[k]==boxes[i])
                            ans=max(ans,dp[k][j][count+1]+dp[i+1][k-1][0]);
                    }
                    dp[i][j][count]=ans;   
                }
            }
        }
        return dp[0][n-1][0];
    }
};