// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod=1003;
int dp[201][201][2];
int solve(int i,int j,string s,bool isTrue)
{
    if(i>j)
    return false;
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
    if(i==j)
    {
        if(isTrue)
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    
    int count=0;
    for(int k=i+1;k<j;k+=2)
    {
       int leftT,rightT,leftF,rightF;
       if(dp[i][k-1][1]!=-1)
       leftT=dp[i][k-1][1];
       else
       leftT=solve(i,k-1,s,1);
       if(dp[k+1][j][1]!=-1)
       rightT=dp[k+1][j][1];
       else
       rightT=solve(k+1,j,s,1);
       if(dp[i][k-1][0]!=-1)
       leftF=dp[i][k-1][0];
       else
       leftF=solve(i,k-1,s,0);
       if(dp[k+1][j][0]!=-1)
       rightF=dp[k+1][j][0];
       else
       rightF=solve(k+1,j,s,0);
       if(s[k]=='&')
       {
           if(isTrue)
           count+=leftT*rightT;
           else
           count+=leftT*rightF+leftF*rightT+leftF*rightF;
       }
       else if(s[k]=='|')
       {
           if(isTrue)
           count+=leftT*rightT+leftF*rightT+leftT*rightF;
           else
           count+=leftF*rightF;
       }
       else if(s[k]=='^')
       {
           if(isTrue)
           count+=leftF*rightT+leftT*rightF;
           else
           count+=leftT*rightT+leftF*rightF;
       }
       count=count%mod;
       dp[i][j][isTrue]=count;
    }
    return count%mod;
}
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,N-1,S,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends