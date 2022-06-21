// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadane(int temp[],int n)
  {
      int curr=temp[0];
      int maxsum=curr;
      for(int i=1;i<n;i++)
      {
          curr=max(curr+temp[i],temp[i]);
          maxsum=max(maxsum,curr);
      }
      return maxsum;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int temp[R];
        int sum,maxsum=INT_MIN;
        for(int left=0;left<C;left++)
        {
            memset(temp,0,sizeof(temp));
            for(int right=left;right<C;right++)
            {
                
                for(int i=0;i<R;i++)
                temp[i]+=M[i][right];
                
                sum=kadane(temp,R);
                if(sum>maxsum)
                maxsum=sum;
            }
        }
        return maxsum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends