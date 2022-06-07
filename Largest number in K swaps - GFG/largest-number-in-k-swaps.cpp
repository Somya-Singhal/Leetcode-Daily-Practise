// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int i,string& s,string& str,int k)
    {
        if(k==0)
        return;
        int max=i;
        for(int x=i+1;x<s.length();x++)
        {
            if(s[max]<s[x])
            {
                 max=x;
            }
        }
        if(s[max]!=s[i])
        --k;
        for(int x=s.length()-1;x>=i;x--)
        {
            if(s[x]==s[max])
            {
                swap(s[x],s[i]);
                if(str.empty() || s.compare(str)>0)
                str=s;
                solve(i+1,s,str,k);
                swap(s[x],s[i]);
            }
        }
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string res="";
       solve(0,str,res,k);
       return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends