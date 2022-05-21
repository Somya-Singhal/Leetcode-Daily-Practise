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
    pair<long long, long long>p;
    int t_min=a[0],t_max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<t_min)
        t_min=a[i];
        if(a[i]>t_max)
        t_max=a[i];
    }
    p.first=t_min,p.second=t_max;
    return p;
}