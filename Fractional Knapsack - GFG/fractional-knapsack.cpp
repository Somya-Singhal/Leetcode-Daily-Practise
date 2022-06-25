// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        pair<double,int>prices[n];
        for(int i=0;i<n;i++)
        {
            prices[i].first=(double)arr[i].value/arr[i].weight;
            prices[i].second=i;
        }
        sort(prices,prices+n,greater<pair<double,int>>());
        double amount=0;
        for(int i=0;i<n;i++)
        {
            if(arr[prices[i].second].weight<=W)
            {
                amount+=arr[prices[i].second].value;
                W-=arr[prices[i].second].weight;
            }
            else
            {
                amount+=arr[prices[i].second].value*((double)W/(double)arr[prices[i].second].weight);
                break;
            }
        }
        return amount;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends