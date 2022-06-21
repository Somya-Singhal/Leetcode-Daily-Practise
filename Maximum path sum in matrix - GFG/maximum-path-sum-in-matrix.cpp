// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>0 && j<n-1)
                {
                    matrix[i][j]+=max(matrix[i-1][j],max(matrix[i-1][j+1],matrix[i-1][j-1]));
                }
                else if(j>0)
                matrix[i][j]+=max(matrix[i-1][j],matrix[i-1][j-1]);
                else if(j<n-1)
                matrix[i][j]+=max(matrix[i-1][j],matrix[i-1][j+1]);
            }
        }
        int maxdist=0;
        for(int i=0;i<n;i++)
        {
            maxdist=max(maxdist,matrix[n-1][i]);
        }
        return maxdist;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends