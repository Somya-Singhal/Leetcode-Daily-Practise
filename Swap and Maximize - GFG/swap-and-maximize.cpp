// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int j=n-1,k=1,large=arr[n-1]+1;
    for(int i=1;i<n;i++)
    {
        if(i%2)
        {
            if(arr[j]>arr[n-1]+1)
            arr[i]=arr[i]*large+(arr[j]/large);
            else
            arr[i]=arr[i]*large+arr[j];
            j--;
        }
        else
        {
            arr[i]=arr[i]*large+(arr[k]/large);
            k++;
        }
    }
    
    long long ans=abs(arr[n-1]%large-arr[0]%large);
    for(int i=1;i<n;i++)
    ans+=abs(arr[i]%large-arr[i-1]%large);
    return ans;
}