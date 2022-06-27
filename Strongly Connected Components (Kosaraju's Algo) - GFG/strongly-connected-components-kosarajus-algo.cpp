// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void postDfs(int i,stack<int>& s,int vis[],vector<int> adj[])
	{
	    vis[i]=1;
	    for(auto x: adj[i])
	    {
	        if(!vis[x])
	        postDfs(x,s,vis,adj);
	    }
	    s.push(i);
	}
	void dfs(int i,int vis[],vector<vector<int>>& rev)
	{
	    vis[i]=1;
	    for(auto x: rev[i])
	    {
	        if(!vis[x])
	        dfs(x,vis,rev);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int>s;
        int vis[V];
        memset(vis,0,sizeof(vis));
        vector<vector<int>>rev(V,vector<int>());
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            postDfs(i,s,vis,adj);
        }
        for(int i=0;i<V;i++)
        {
            for(auto x: adj[i])
            rev[x].push_back(i);
        }
        memset(vis,0,sizeof(vis));
        int count=0;
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            if(!vis[i])
            {
                dfs(i,vis,rev);
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends