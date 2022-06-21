// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
bool solve(string a,unordered_set<string>& dict,unordered_map<string,bool>& dp)
{
    if(a.length()==0)
    return true;
    if(dp.find(a)!=dp.end())
    return dp[a];
    for(int i=1;i<=a.length();i++)
    {
        if(dict.find(a.substr(0,i))!=dict.end() && solve(a.substr(i),dict,dp))
        {
            return dp[a]=true;
        }
    }
    return dp[a]=false;
}
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>dict(B.begin(),B.end());
        unordered_map<string,bool>dp;
        return solve(A,dict,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends