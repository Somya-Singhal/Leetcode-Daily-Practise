class Solution {
public:
    //dijsktra without priority queue
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
         vector<bool>vis(n,false);
        if(n==1)
            return 0;
        int steps=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                int j=q.front();
                vis[j]=true;
                q.pop();
                if(j>0 && mp.find(arr[j-1])!=mp.end() && !vis[j-1])
                {
                   q.push(j-1);
                    vis[j-1]=true;
                }
                if(j<n-1 && mp.find(arr[j+1])!=mp.end() && !vis[j+1])
                {
                    if(j+1==n-1)
                        return steps;
                    q.push(j+1);
                    vis[j+1]=true;
                }
                if(mp.find(arr[j])!=mp.end())
                {
                    for(auto x:mp[arr[j]])
                    {
                        if(x!=j  && !vis[x])
                        {
                            if(x==n-1)
                                return steps;
                            q.push(x);
                            vis[x]=true;
                        }
                    }
                }
                mp.erase(arr[j]);
            }
        }
        return steps;
    }
};