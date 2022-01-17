class Solution {
public:
    //dijsktra without priority queue
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
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
                q.pop();
                if(j>0 && mp.find(arr[j-1])!=mp.end())
                    q.push(j-1);
                if(j<n-1 && mp.find(arr[j+1])!=mp.end())
                {
                    if(j+1==n-1)
                        return steps;
                    q.push(j+1);
                }
                if(mp.find(arr[j])!=mp.end())
                {
                    for(auto x:mp[arr[j]])
                    {
                        if(x!=j)
                        {
                            if(x==n-1)
                                return steps;
                            q.push(x);
                        }
                    }
                }
                mp.erase(arr[j]);
            }
        }
        return steps;
    }
};