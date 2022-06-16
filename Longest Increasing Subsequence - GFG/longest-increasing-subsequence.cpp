// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int findidx(vector<int>b,int lo,int hi,int key)
    {
        while(hi-lo>1)
        {
            int m=lo+(hi-lo)/2;
            if(b[m]>=key)
            hi=m;
            else
            lo=m;
        }
        return hi;
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>b(n,0);
       b[0]=a[0];
       int len=1;
       for(int i=1;i<n;i++)
       {
           if(a[i]<b[0])
           b[0]=a[i];
           else if(a[i]>b[len-1])
           b[len++]=a[i];
           else
           b[findidx(b,-1,len-1,a[i])]=a[i];
       }
       return len;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends