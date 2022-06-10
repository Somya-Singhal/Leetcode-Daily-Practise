// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool palindrome(string s)
  {
      int lo=0,hi=s.length()-1;
      while(lo<hi)
      {
          if(s[lo]!=s[hi])
          return false;
          lo++;
          hi--;
      }
      return true;
  }
    void solve(int i,string s,vector<string>& str,vector<vector<string>>& res)
    {
        if(i==s.length())
        {
            res.push_back(str);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            if(palindrome(s.substr(i,j-i+1))==true)
            {
                str.push_back(s.substr(i,j-i+1));
                solve(j+1,s,str,res);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>res;
        vector<string>str;
        solve(0,S,str,res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends