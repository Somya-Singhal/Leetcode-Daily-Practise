class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long int x=pow(abs(bombs[j][0]-bombs[i][0]),2);
                    long long int y=pow(abs(bombs[j][1]-bombs[i][1]),2);
                    long long int total=x+y;
                    float dist=sqrt(total);
                    if(dist<=bombs[i][2])
                        adj[i].push_back(j);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<bool>vis(n,false);
            int count=1;
            queue<int>q;
            q.push(i);
            vis[i]=true;
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                for(auto x: adj[curr])
                {
                    if(!vis[x])
                    {
                        vis[x]=true;
                        q.push(x);
                        count++;
                    }
                }
            }
             ans=max(ans,count);
        }
        return ans;
    }
};