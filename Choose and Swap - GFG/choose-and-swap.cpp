// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        char found,replace;
        int i,j;
        vector<int>freq(26,0);
        for(i=0;i<26;i++)
        {
            freq[i]=-1;
        }
        for(i=0;i<a.length();i++)
        {
            if(freq[a[i]-'a']==-1)
            freq[a[i]-'a']=i;
        }
        
        for(i=0;i<a.length();i++)
        {
            bool flag=false;
            for(j=0;j<a[i]-'a';j++)
            {
                if(freq[j]>freq[a[i]-'a'])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            break;
        }
        
        if(i<a.length())
        {
            
            char ch1=a[i];
            char ch2=char(j+'a');
            
            for(int k=0;k<a.length();k++)
            {
                if(a[k]==ch1)
                a[k]=ch2;
                else if(a[k]==ch2)
                a[k]=ch1;
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends