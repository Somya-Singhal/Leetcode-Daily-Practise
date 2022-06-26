// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int starting_pt[102];
    int ending_pt[102];
    int diameter_btw[102];
    int dfs(int idx,int *val)
    {
        if(starting_pt[idx]==0)
        return idx;
        if(diameter_btw[idx]<*val)
        *val=diameter_btw[idx];
        return dfs(starting_pt[idx],val);
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<int>>ans;
        
        memset(starting_pt,0,sizeof(starting_pt));
        memset(ending_pt,0,sizeof(ending_pt));
        memset(diameter_btw,0,sizeof(diameter_btw));
        for(int i=0;i<p;i++)
        {
            int h1=a[i],h2=b[i],dia=d[i];
            starting_pt[h1]=h2;
            ending_pt[h2]=h1;
            diameter_btw[h1]=dia;
        }
        for(int j=1;j<=n;j++)
        {
            if(ending_pt[j]==0 && starting_pt[j])
            {
                vector<int>v(3,0);
                int mindia=105;
                int w=dfs(j,&mindia);
                v[0]=j;
                v[1]=w;
                v[2]=mindia;
                ans.push_back(v);
            }
            
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends