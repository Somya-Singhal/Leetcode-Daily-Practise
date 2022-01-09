class Solution {
public:
   //dfs
    bool isvalid(int i,vector<int>& color,int parent,int currcolor,vector<vector<int>>& graph)
    {
        if(color[i]!=0)
            return color[i]!=color[parent];
        color[i]=currcolor;
        for(auto x:graph[i])
        {
            if(!isvalid(x,color,i,-currcolor,graph))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
           if(color[i]==0 && !isvalid(i,color,-1,1,graph))
               return false;
        }
        return true;
    }
};