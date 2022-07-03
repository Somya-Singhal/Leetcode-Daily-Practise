// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        vector<int>pos;
        int n=S.length();
        for(int i=0;i<n;i++)
        {
            if(S[i]=='[')
            pos.push_back(i);
        }
        int count=0,p=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='[')
            {
                ++count;
                ++p;
            }
            else
            {
                --count;
                if(count<0)
                {
                    ans+=pos[p]-i;
                    swap(S[i],S[pos[p]]);
                    ++p;
                    count=1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends