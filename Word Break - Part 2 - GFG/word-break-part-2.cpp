// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int i,unordered_set<string>& worddict,string s,string str,vector<string>& res)
    {
        if(i==s.length())
        {
            res.push_back(str.substr(1));
            return;
        }
        str+=" ";
        for(int j=i;j<s.length();j++)
        {
            string t=s.substr(i,j-i+1);
            if(worddict.find(t)!=worddict.end())
            {
                solve(j+1,worddict,s,str+t,res);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>res;
        unordered_set<string>worddict;
        
        for(auto x: dict)
          worddict.insert(x);
        solve(0,worddict,s,"",res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends