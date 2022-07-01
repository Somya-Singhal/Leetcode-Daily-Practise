// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(int l,int r,string S,vector<string>& res)
	    {
	        if(l==r)
	        {
	            res.push_back(S);
	            return;
	        }
	        for(int i=l;i<=r;i++)
	        {
	            if(i>0 && S[i]==S[i-1])
	            continue;
	            swap(S[l],S[i]);
	            solve(l+1,r,S,res);
	            swap(S[l],S[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>res;
		    sort(S.begin(),S.end());
		    solve(0,S.length()-1,S,res);
		    sort(res.begin(),res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends