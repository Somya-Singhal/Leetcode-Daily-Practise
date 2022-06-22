// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool ispalindrome(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int solve(int i,int j,string s,vector<vector<int>>& dp)
{
    if(i>=j || ispalindrome(i,j,s))
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
       int left=INT_MAX,right=INT_MAX;
       if(dp[i][k]!=-1)
       left=dp[i][k];
       else{
           left=solve(i,k,s,dp);
           dp[i][k]=left;
       }
       if(dp[k+1][j]!=-1)
       right=dp[k+1][j];
       else
       {
           right=solve(k+1,j,s,dp);
           dp[k+1][j]=right;
       }
       int c=1+left+right;
        if(c<ans)
        ans=c;
    }
    return dp[i][j]=ans;
}
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,str,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends