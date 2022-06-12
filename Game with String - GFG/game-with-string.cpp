// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>m;
        priority_queue<int,vector<int>>pq;
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(auto x: m)
        {
            pq.push(x.second);
        }
        while(k>0)
        {
            int t=pq.top();
            pq.pop();
            t=t-1;
            if(t>0)
            pq.push(t);
            k--;
        }
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            sum+=x*x;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends