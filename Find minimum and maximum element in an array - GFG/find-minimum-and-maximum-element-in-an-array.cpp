// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long>minmax;
    int i=0;
    if(n%2==0)
    {
        if(a[0]<a[1])
        {
            minmax.first=a[0],minmax.second=a[1];
        }
        else
        minmax.second=a[0],minmax.first=a[1];
        i+=2;
    }
    else
    {
        minmax.first=a[0],minmax.second=a[1];
        i++;
    }
    while(i<n-1)
    {
        if(a[i]>a[i+1])
        {
            if(a[i]>minmax.second)
            {
                minmax.second=a[i];
            }
            if(a[i+1]<minmax.first)
            minmax.first=a[i+1];
        }
        else{
           if(a[i+1]>minmax.second)
             minmax.second=a[i+1];
           if(a[i]<minmax.first)
            minmax.first=a[i];
        }
        i+=2;
    }
    return minmax;
}