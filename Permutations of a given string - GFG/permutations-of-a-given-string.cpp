// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(string s,string str,set<string>& st,vector<int>& vis)
	    {
	        if(str.length()==s.length())
	        {
	           st.insert(str);
	           return;
	        }
	        for(int i=0;i<s.length();i++)
	        {
	            if(vis[i]==1)
	            continue;
	            vis[i]=1;
	            str+=s[i];
	            solve(s,str,st,vis);
	            vis[i]=0;
	            str.pop_back();
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		  //  sort(S.begin(),S.end());
		    set<string>st;
		    vector<string>res;
		    vector<int>vis(S.length(),0);
		    solve(S,"",st,vis);
		    for(auto x: st)
		    {
		        res.push_back(x);
		    }
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