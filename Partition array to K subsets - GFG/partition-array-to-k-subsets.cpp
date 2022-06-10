// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool solve(int i,vector<int>& stsum,vector<bool>& vis,int subsum,int a[],int n,int k)
  {
      if(stsum[i]==subsum)
      {
          if(i==k-2)
          return true;
          return solve(i+1,stsum,vis,subsum,a,n,k);
      }
          for(int j=0;j<n;j++)
          {
              if(vis[j]==true)
              continue;
              if(stsum[i]+a[j]<=subsum)
              {
                  vis[j]=true;
                  stsum[i]+=a[j];
                  if(solve(i,stsum,vis,subsum,a,n,k))
                     return true;
                  vis[j]=false;
                  stsum[i]-=a[j];
              }
          }
        return false;
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         if(k==1)
         return true;
         if(n<k)
         return false;
         int sum=0;
         vector<int>stsum(k,0);
         vector<bool>vis(n,0);
         for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         if(sum%k)
         return false;
         int subsum=sum/k;
         return solve(0,stsum,vis,subsum,a,n,k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends