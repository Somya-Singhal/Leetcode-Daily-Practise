// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int mid,int a[],int n,int m)
    {
        int sum=0,st=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid)
            return false;
            if(sum+a[i]>mid)
            {
                st++;
                sum=a[i];
                if(st>m)
                  return false;
            }
            else
            sum+=a[i];
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
        return -1;
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=A[i];
        int lo=A[0],hi=sum,ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(isPossible(mid,A,N,M))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                 lo=mid+1;
            }
           
        }
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends