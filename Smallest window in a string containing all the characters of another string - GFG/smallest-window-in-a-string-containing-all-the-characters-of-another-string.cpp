// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>count1(256,0),count2(256,0);
        int n1=s.length(),n2=p.length();
        for(int i=0;i<n2;i++)
        {
            count1[p[i]-'a']++;
        }
        int start=0,start_idx=-1,len=INT_MAX;
        int count=0;
        for(int i=0;i<n1;i++)
        {
            count2[s[i]-'a']++;
            if(count2[s[i]-'a']<=count1[s[i]-'a'])
            count++;
            if(count==n2)
            {
                while(count2[s[start]-'a']>count1[s[start]-'a'] || count1[s[start]-'a']==0)
                {
                    if(count2[s[start]-'a']>count1[s[start]-'a'])
                    count2[s[start]-'a']--;
                    start++;
                }
                int currlen=i-start+1;
                if(currlen<len)
                {
                    len=currlen;
                    start_idx=start;
                }
            }
        }
        if(start_idx==-1)
        return "-1";
        return s.substr(start_idx,len);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends