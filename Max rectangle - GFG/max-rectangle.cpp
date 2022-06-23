// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>temp(m);
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==0)
                temp[j]=0;
                else
                temp[j]+=M[i][j];
            }
            
            stack<int>s;
            int k=0;
            while(k<m)
            {
                if(s.empty() || temp[s.top()]<=temp[k])
                s.push(k++);
                else
                {
                    int t=s.top();
                    s.pop();
                    int area=temp[t]*(s.empty()?k:(k-s.top()-1));
                    maxarea=max(maxarea,area);
                }
            }
            while(!s.empty())
            {
                int t=s.top();
                s.pop();
                int area=temp[t]*(s.empty()?m:(m-s.top()-1));
                maxarea=max(maxarea,area);
            }
            // cout<<maxarea<<" ";
        }
        return maxarea;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends