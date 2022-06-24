// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long solve(long long arr[],vector<long long>& temp,long long lo,long long hi)
    {
        long long count=0;
        if(lo<hi)
        {
            long long mid=lo+(hi-lo)/2;
            count+=solve(arr,temp,lo,mid);
            count+=solve(arr,temp,mid+1,hi);
            count+=merge(arr,temp,lo,mid+1,hi);
        }
        return count;
    }
    long long merge(long long arr[],vector<long long>& temp,long long lo,long long mid,long long hi)
    {
        long long i=lo,j=mid,k=lo,count=0;
        while(i<mid && j<=hi)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                count+=mid-i;
            }
        }
        while(i<mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=hi)
        {
            temp[k++]=arr[j++];
        }
        for(int i=lo;i<=hi;i++)
        arr[i]=temp[i];
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        vector<long long>temp(N,0);
        return solve(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends