// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        
        int lo=0,hi=5*n;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            int f=5,count=0;
            while(f<=mid)
            {
                count+=mid/f;
                f*=5;
            }
            if(count<n)
            lo=mid+1;
            else
            {
                hi=mid; 
            }
           
        }
        return lo;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends