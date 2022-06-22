// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    unordered_map<string,bool>m;
   bool solve(int i,int j,string a,string b,string c)
   {
       int n3=c.length(),n1=a.length(),n2=b.length();
       if(n3==0 && i==n1 && j==n2)
       return true;
       string str=to_string(i)+""+to_string(j)+""+c;
       if(m.find(str)!=m.end())
       return m[str];
       if(a[i]==c[0] && b[j]==c[0])
       return m[str]=solve(i+1,j,a,b,c.substr(1)) || solve(i,j+1,a,b,c.substr(1));
       else if(a[i]==c[0])
       return m[str]=solve(i+1,j,a,b,c.substr(1));
       else if(b[j]==c[0])
       return m[str]=solve(i,j+1,a,b,c.substr(1));
       
       return m[str]=false;
   }
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        int n1=a.length(),n2=b.length(),n3=c.length();
        if(n1==0)
        return b==c;
        if(n2==0)
        return a==c;
        if(n3!=n1+n2)
        return false;
        // vector<vector<int>>dp(n1,vector<int>(n2,0));
        // int k=0;
        // for(int i=0;i<n1;i++)
        // {
        //     for(int j=0;j<n2;j++)
        //     {
        //         if(a[i]==c[k] && b[j]==c[k])
        //         dp[i][j]=dp[i-1][j] || dp[i][j-1];
        //         else if(a[i]==c[k])
        //         dp[i][j]=dp[i-1][j];
        //         else if(b[j]==c[k])
        //         dp[i][j]=dp[i][j-1];
        //         else
        //         return false;
        //         k++;
        //     }
        // }
        // return k==n3;
        return solve(0,0,a,b,c);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends