class mytuple{
    int bitmask,node,cost;
    public:
    mytuple(int b,int n,int c)
    {
        bitmask=b;
        node=n;
        cost=c;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        set<pair<int,pair<int,int>>>s;
        queue<pair<int,pair<int,int>>>q;
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            int bitmask=(1<<i);
            s.insert(make_pair(bitmask,make_pair(i,0)));
            q.push(make_pair(bitmask,make_pair(i,1)));
        }
        while(!q.empty())
        {
            int bitset=q.front().first;
            int curr=q.front().second.first;
            int currcost=q.front().second.second;
            q.pop();
            if(bitset==((1<<n)-1))
                return currcost-1;
            else
            {
                for(auto x:graph[curr])
                {
                    int bitmask=bitset|(1<<x);
                    if(s.find(make_pair(bitmask,make_pair(x,0)))==s.end())
                    {
                        q.push(make_pair(bitmask,make_pair(x,currcost+1)));
                        s.insert(make_pair(bitmask,make_pair(x,0)));
                    }
                } 
            }
        }
        return -1;
    }
};