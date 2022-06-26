// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        vector<int>freq(26,0);
        string res="";
        pair<int,char>prev={-1,'#'};
        for(int i=0;i<str.length();i++)
        freq[str[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            pq.push({freq[i],i+'a'});
        }
        while(!pq.empty())
        {
            char c=pq.top().second;
            int f=pq.top().first;
            pq.pop();
            res+=c;
            if(prev.first>0)
            pq.push({prev.first,prev.second});
            f-=1;
            prev.first=f;
            prev.second=c;
            
        }
        return res.length()!=str.length()?"-1":res;
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends