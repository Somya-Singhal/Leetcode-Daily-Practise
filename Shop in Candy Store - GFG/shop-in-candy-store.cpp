// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        vector<int>res(2,0);
        int lo=0,hi=N-1,minamount=0,maxamount=0;
        while(lo<=hi)
        {
            minamount+=candies[lo];
            lo++;
            hi-=K;
        }
        lo=0,hi=N-1;
        while(lo<=hi)
        {
            maxamount+=candies[hi];
            hi--;
            lo+=K;
        }
        res[0]=minamount,res[1]=maxamount;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends