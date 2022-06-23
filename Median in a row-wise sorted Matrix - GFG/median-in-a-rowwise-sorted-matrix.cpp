// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        int cmin=INT_MAX,cmax=INT_MIN;
        for(int i=0;i<r;i++)
        {
             cmin=min(cmin,matrix[i][0]);
             cmax=max(cmax,matrix[i][c-1]);
        }
        int desired=(r*c+1)/2;
        
       while(cmin<=cmax)
       {
           int mid=cmin+(cmax-cmin)/2;
           int count=0;
           for(int i=0;i<r;i++)
           {
               int lo=0,hi=c-1,ans=0;
               while(lo<=hi)
               {
                   int idx=lo+(hi-lo)/2;
                   if(matrix[i][idx]<=mid)
                   {
                       ans=idx+1;
                       lo=idx+1;
                   }
                   
                   else
                   hi=idx-1;
               }
              count+=ans; 
           }
           if(count>=desired)
            cmax=mid-1;
           else
            cmin=mid+1;
       }
       return cmin; 
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends