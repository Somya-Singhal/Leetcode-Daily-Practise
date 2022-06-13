// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    // int dx[8]={-2,-1,-2,-1,1,2,1,2},dy[8]={-1,-2,1,2,2,1,-2,-1};
    bool valid(int x,int y,int n)
    {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    //Function to find out minimum steps Knight needs to reach target position.
    int bfs(vector<int>&k,vector<int>&t,int N,vector<vector<int>>&vis)
    {
        queue<vector<int>>q;
        vis[k[0]][k[1]]=1;
        vector<int>v(3,0);
        v[0]=k[0],v[1]=k[1];
        q.push(v);
        while(!q.empty())
        {
            
            vector<int>top=q.front();
            int x=top[0];
            int y=top[1];
            int dist=top[2];
            q.pop();
            if((x==t[0]) && (y==t[1]))
            return dist;
            
            for(int j=0;j<8;j++)
            {
                int newx=x+dx[j];
                int newy=y+dy[j];
                if(valid(newx,newy,N) && vis[newx][newy]==0)
                {
                    vis[newx][newy]=1;
                    vector<int>temp(3,0);
                    temp[0]=newx,temp[1]=newy,temp[2]=dist+1;
                    q.push(temp);
                }
            }
            
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	   vector<vector<int>>vis(N,vector<int>(N,0));
	   KnightPos[0]--,KnightPos[1]--;
	   TargetPos[0]--,TargetPos[1]--;
	    return bfs(KnightPos,TargetPos,N,vis);
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends