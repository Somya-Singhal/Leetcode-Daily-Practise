// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int setbits(int arr[],int i,int n)
    {
        int num=arr[i],count=0;
        while(num)
        {
            if(num & 1)
            count++;
            num=num>>1;
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>>v(32);
        for(int i=0;i<n;i++)
        {
            int count=setbits(arr,i,n);
            v[count].push_back(arr[i]);
        }
        int j=0;
        for(int i=31;i>=0;i--)
        {
            vector<int>temp=v[i];
            for(int k=0;k<temp.size();k++)
            arr[j++]=temp[k];
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends