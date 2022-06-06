// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    bool valid(int i,int j,vector<vector<int>> &m,int n)
    {
        return (i>=0 && i<n && j>=0 && j<n && m[i][j]==1);
    }
    void solve(vector<vector<int>> &m, int n,int x,int y,string str,vector<string>& res,vector<vector<int>>& vis)
    {
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(i==0)
            str+='U';
            else if(i==1)
            str+='R';
            else if(i==2)
            str+='D';
            else
            str+='L';
            if(valid(newx,newy,m,n) && vis[newx][newy]==0)
            {
                vis[newx][newy]=1;
                if(newx==n-1 && newy==n-1)
                {
                    res.push_back(str);
                }
                else{
                solve(m,n,newx,newy,str,res,vis);
                }
                vis[newx][newy]=0;
            }
            str.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==0)
        return res;
        vis[0][0]=1;
        solve(m,n,0,0,"",res,vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends