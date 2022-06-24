// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>s;
      int maxcount=0;
      for(int i=0;i<N;i++)
      s.insert(arr[i]);
      for(int i=0;i<N;i++)
      {
          int count=0;
          if(s.find(arr[i]-1)==s.end())
          {
              count++;
              int num=arr[i];
              while(s.find(num+1)!=s.end())
              {
                  count++;
                  num+=1;
              }
              
              maxcount=max(maxcount,count);
          }
      }
      return maxcount;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends