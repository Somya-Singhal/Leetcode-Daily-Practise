// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0)
        return -1;
        int idx=0,count=0;
        while(N){
            if(N & (N-1))
            {
                ++count;
            }
            else
            ++idx;
            if(count>1)
            return -1;
            N=N>>1;
        }
        return idx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends