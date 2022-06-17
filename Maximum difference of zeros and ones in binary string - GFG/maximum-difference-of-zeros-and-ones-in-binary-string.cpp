// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.length();
	    
	    int curr=(S[0]=='1')?-1:1;
	    int maxend=curr;
	    for(int i=1;i<n;i++)
	    {
	        int val;
	        if(S[i]=='1')
	        val=-1;
	        else
	        val=1;
	        curr=max(curr+val,val);
	        maxend=max(maxend,curr);
	    }
	    return maxend;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends