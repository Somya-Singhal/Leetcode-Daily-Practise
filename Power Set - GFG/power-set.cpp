// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void solve(int i,string s,string str,vector<string>& res)
	{
	    if(i==s.length())
	    {
	        if(str!="")
	        res.push_back(str);
	        return;
	    }
	    
	        solve(i+1,s,str+s[i],res);
	        solve(i+1,s,str,res);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>res;
		  //  int len=pow(2,s.length());
		  //  for(int j=1;j<=len;j++){
		  //      int temp=j;
		  //      string ans="";
		  //      for(int i=0;i<s.length() && temp>0;i++)
		  //      {
		  //          if(temp&1)
		  //          ans+=s[i];
		  //          temp=temp>>1;
		  //      }
		  //      if(ans!="")
		  //      res.push_back(ans);
		  //  }
		  //  sort(res.begin(),res.end());
		  //  return res;
		  
		  solve(0,s,"",res);
		  sort(res.begin(),res.end());
		  return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends