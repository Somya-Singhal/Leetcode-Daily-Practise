// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        // int count=0;
        // while(dividend>=divisor)
        // {
        //     ++count;
        //     dividend-=divisor;
        // }
        // return count;
      int sign=(dividend<0)^(divisor<0)?-1:1;
      dividend=abs(dividend);
      divisor=abs(divisor);
      long long temp=0,quotient=0;
      for(int i=31;i>=0;i--)
      {
          if(temp+(divisor<<i)<=dividend)
          {
              temp+=(divisor<<i);
              quotient |=1LL<<i;
          }
      }
       return (sign==-1)?-quotient:quotient; 
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends