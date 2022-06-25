// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S>9*D)
        return "-1";
        if(D==1)
        return to_string(S);
        int temp=D-1;
        string res="1";
        S--;
        while(temp>1)
        {
            res+='0';
            temp--;
        }
        int last=min(9,S);
        res+=to_string(last);
        
        int n=res.length();
        int carry=S-last;
        
        for(int i=n-2;i>=0;i--)
        {
            if(res[i]+carry-'0'>9)
            {
                int num=res[i]+carry-'0';
                res[i]='9';
                carry=num-9;
            }
            else
            {
                int num=res[i]-'0'+carry;
                res[i]=num+'0';
                carry=0;
            }
            
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends