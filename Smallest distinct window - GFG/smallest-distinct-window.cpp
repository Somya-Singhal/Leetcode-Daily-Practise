// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char>s;
        unordered_map<char,int>mp;
        int n=str.length();
        int need=0;
        for(int i=0;i<n;i++)
        {
            if(s.find(str[i])==s.end())
            {
                 need++;
                 s.insert({str[i]});
            }
           
        }
        int have=0,l=0,minlen=INT_MAX;
        for(int r=0;r<n;r++)
        {
            int c=str[r];
            mp[c]++;
            if(mp[c]==1)
            have++;
            while(have==need)
            {
                if(r-l+1<minlen)
                {
                    minlen=r-l+1;
                }
                mp[str[l]]--;
                if(mp[str[l]]==0)
                have--;
                l++;
            }
        }
        return minlen;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends