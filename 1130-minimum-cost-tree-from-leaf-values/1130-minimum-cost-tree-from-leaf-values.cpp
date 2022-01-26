class Solution {
public:
    //recursion-1
    // vector<int> solve(int s,int e,vector<int>& arr)
    // {
    //     if(s>=e)
    //         return {arr[s],0};
    //     int res=INT_MAX,maxx,maxy;
    //     for(int i=s;i<e;i++)
    //     {
    //         auto left=solve(s,i,arr);
    //         auto right=solve(i+1,e,arr);
    //         maxx=left[0];
    //         maxy=right[0];
    //         res=min(res,maxx*maxy+left[1]+right[1]); 
    //     }
    //   return {max(maxx,maxy),res};
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     auto p=solve(0,n-1,arr);
    //     return p[1];
    // }
    
    //recursion-2
    // int solve(int s,int e,vector<int>& arr)
    // {
    //     if(s>=e)
    //         return 0;
    //     int res=INT_MAX;
    //     for(int i=s;i<e;i++)
    //     {
    //         int maxx=INT_MIN,maxy=INT_MIN;
    //         for(int t=s;t<=i;t++)
    //             maxx=max(maxx,arr[t]);
    //         for(int t=i+1;t<=e;t++)
    //             maxy=max(maxy,arr[t]);
    //         // cout<<maxx<<" "<<maxy<<endl;
    //        res=min(res,maxx*maxy+solve(s,i,arr)+solve(i+1,e,arr)); 
    //     }
    //   return res;
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     return solve(0,n-1,arr);
    // }
    
    //bottom-up(memo)
    // int solve(int s,int e,vector<int>& arr,vector<vector<int>>& dp)
    // {
    //     if(dp[s][e]!=0)
    //         return dp[s][e];
    //     if(s>=e)
    //         return 0;
    //     int res=INT_MAX;
    //     for(int i=s;i<e;i++)
    //     {
    //         int maxx=INT_MIN,maxy=INT_MIN;
    //         for(int t=s;t<=i;t++)
    //             maxx=max(maxx,arr[t]);
    //         for(int t=i+1;t<=e;t++)
    //             maxy=max(maxy,arr[t]);
    //         // cout<<maxx<<" "<<maxy<<endl;
    //        res=min(res,maxx*maxy+solve(s,i,arr,dp)+solve(i+1,e,arr,dp)); 
    //     }
    //   return dp[s][e]=res;
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     return solve(0,n-1,arr,dp);
    // }
    
    //top-down: time:O(n^4), space:O(n^2)
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     for(int gap=0;gap<n;gap++)
    //     {
    //         for(int i=0,j=gap;j<n;i++,j++)
    //         {
    //             if(j==i+1)
    //                 dp[i][j]=arr[i]*arr[j];
    //             else
    //             {
    //                 int ans=INT_MAX;
    //                 for(int k=i;k<j;k++)
    //                 {
    //                     int maxx=INT_MIN,maxy=INT_MIN;
    //                     for(int t=i;t<=k;t++)
    //                     {
    //                         maxx=max(maxx,arr[t]);
    //                     }  
    //                     for(int t=k+1;t<=j;t++)
    //                     {
    //                         maxy=max(maxy,arr[t]);
    //                     }
    //                     // cout<<maxx*maxy+dp[i][k]+dp[k+1][j]<<endl;
    //                     ans=min(ans,maxx*maxy+dp[i][k]+dp[k+1][j]);
    //                     dp[i][j]=ans;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][n-1];
    // }
    
    //time->O(n^2)
     int mctFromLeafValues(vector<int>& arr) {
        int res=0;
         while(arr.size()>1)
         {
             int index,minval=INT_MAX;
             for(int i=0;i<arr.size();i++)
             {
                 if(arr[i]<minval)
                 {
                     minval=arr[i];
                     index=i;
                 }
             }
             if(index>0 && index<arr.size()-1)
                 res+=arr[index]*min(arr[index-1],arr[index+1]);
             else
             {
                 if(index==0)
                     res+=arr[index]*arr[index+1];
                 else
                     res+=arr[index]*arr[index-1];
             }
             arr.erase(arr.begin()+index);
         }
         return res;
    }
    
};