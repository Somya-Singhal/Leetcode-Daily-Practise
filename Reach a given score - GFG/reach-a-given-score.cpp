// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1; 
	// If 0 sum is required number of ways is 1.
	int score[3]={3,5,10};
	
	    for(i=0;i<3;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
    	        if(score[i]<=j)
    	          table[j]+=table[j-score[i]];
	        }
	    }
	
	// Your code here
	
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends