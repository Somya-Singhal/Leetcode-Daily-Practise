// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int>v;
        int count=0;
        for(int i=0;i<N;i++)
        {
            auto it=find(v.begin(),v.end(),pages[i]);
            if(it!=v.end())
            {
                v.erase(it);
                v.push_back(pages[i]);
            }
            else
            {
                if(v.size()==C)
                v.erase(v.begin());
                count++;
                v.push_back(pages[i]);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends