class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indegree(n+2,0);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[u]++;
            indegree[v]++;
        }
        int ans;
        for(int i=1;i<n+2;i++)
        {
            if(indegree[i]==n)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};