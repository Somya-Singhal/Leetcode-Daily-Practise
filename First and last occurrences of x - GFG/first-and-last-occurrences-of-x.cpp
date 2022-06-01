// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int lo=0,hi=n-1;
    vector<int>v(2,-1);
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if((mid==0 || arr[mid-1]<x) && arr[mid]==x)
        {
            v[0]=mid;
            break;
        } else if(arr[mid]<x)
        {
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    lo=0,hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if((mid==n-1 || arr[mid+1]>x) && arr[mid]==x)
        {
            v[1]=mid;
            break;
        } else if(arr[mid]>x)
        {
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends