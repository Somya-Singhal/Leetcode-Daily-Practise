// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i,vector<vector<int>>& res,vector<int>v,vector<int> &A, int B)
    {
        if(B<0 || i>=A.size())
        return;
        if(B==0)
        {
            res.push_back(v);
            return;
        }
        if(A[i]<=B)
        {
            v.push_back(A[i]);
            solve(i,res,v,A,B-A[i]);
            v.pop_back();
            solve(i+1,res,v,A,B);
        }
        else
        solve(i+1,res,v,A,B);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>res;
        vector<int>v;
        sort(A.begin(),A.end());
        
            A.erase(unique(A.begin(),A.end()),A.end());
        solve(0,res,v,A,B);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends