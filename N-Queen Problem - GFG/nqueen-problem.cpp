// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool valid(int x,int y,int n,vector<vector<int>>& Q)
{
    for(int i=0;i<y;i++)
    {
        if(Q[x][i]==1)
        return false;
    }
    for(int i=x,j=y;i>=0&&j>=0;i--,j--)
    {
        if(Q[i][j]==1)
        return false;
    }
    for(int i=x,j=y;i<n&&j>=0;i++,j--)
    {
        if(Q[i][j]==1)
        return false;
    }
    return true;
}
  bool solve(int n,int i,vector<vector<int>>& res,vector<vector<int>>& Q)
  {
      if(i==n)
      {
          vector<int>v;
          for(int j=0;j<n;j++)
          {
              for(int k=0;k<n;k++)
              if(Q[j][k]==1)
              v.push_back(k+1);
          }
          res.push_back(v);
          return true;
      }
      bool flag=false;
      for(int j=0;j<n;j++)
      {
          if(valid(j,i,n,Q))
          {
              Q[j][i]=1;
              
              flag |= solve(n,i+1,res,Q);
              
              
              Q[j][i]=0;
          }
      }
      return flag;
  }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res;
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(n,0,res,board);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends