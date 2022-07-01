// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
void reverse(vector<int>& arr,int s,int e)
{
    int lo=s,hi=e-1;
    while(lo<hi)
    {
        swap(arr[lo],arr[hi]);
        lo++;
        hi--;
    }
}
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx=-1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                idx=i;
                break;
            }
        }
        if(idx!=-1)
        {
            int i;
            for(i=N-1;i>=0;i--)
            {
                if(arr[i]>arr[idx])
                break;
            }
            swap(arr[i],arr[idx]);
            reverse(arr,idx+1,N);
        }
        else
        reverse(arr,0,N);
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends