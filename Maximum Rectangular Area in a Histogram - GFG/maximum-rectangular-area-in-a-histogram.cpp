// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long>s;
        int i=0;
        long long maxarea=LONG_LONG_MIN;
        while(i<n)
        {
            if(s.empty() || arr[s.top()]<=arr[i])
            s.push(i++);
            else{
                int t=s.top();
                s.pop();
                long long curr=arr[t]*(s.empty()?i:(i-s.top()-1));
                maxarea=max(maxarea,curr);
            }
        }
        while(s.empty()==false)
        {
            int t=s.top();
            s.pop();
            long long curr=arr[t]*(s.empty()?i:(i-s.top()-1));
            maxarea=max(maxarea,curr);
        }
        return maxarea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends