// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int cmin=mat[0][0],cmax=mat[n-1][n-1];
  while(cmin<=cmax)
  {
      int mid=cmin+(cmax-cmin)/2;
      int count=0;
      for(int i=0;i<n;i++)
      {
          int lo=0,hi=n-1,ans=0;
          while(lo<=hi)
          {
              int inmid=lo+(hi-lo)/2;
              if(mat[i][inmid]<=mid)
              {
                  ans=inmid+1;
                  lo=inmid+1;
              }
              else
              hi=inmid-1;
          }
          count+=ans;
          
      }
      
      if(count>=k)
      cmax=mid-1;
      else
      cmin=mid+1;
  }
  return cmin;
}
