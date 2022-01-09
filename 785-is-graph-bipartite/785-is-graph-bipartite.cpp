class Solution {
public:
   //dfs
    // bool isvalid(int i,vector<int>& color,int parent,int currcolor,vector<vector<int>>& graph)
    // {
    //     if(color[i]!=0)
    //         return color[i]!=color[parent];
    //     color[i]=currcolor;
    //     for(auto x:graph[i])
    //     {
    //         if(!isvalid(x,color,i,-currcolor,graph))
    //             return false;
    //     }
    //     return true;
    // }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n=graph.size();
    //     vector<int>color(n,0);
    //     for(int i=0;i<n;i++)
    //     {
    //        if(color[i]==0 && !isvalid(i,color,-1,1,graph))
    //            return false;
    //     }
    //     return true;
    // }
    
    //bfs
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
               queue<int>q;
               q.push(i);
               color[i]=1;
                while(!q.empty())
                {
                    int i=q.front();
                    q.pop();
                    for(auto x: graph[i])
                    {
                        if(color[x]==0)
                        {
                            color[x]=-color[i];
                            q.push(x);
                        }
                        else if(color[x]==color[i])
                            return false;
                    }
                }
            } 
        }
        return true;
    }
};