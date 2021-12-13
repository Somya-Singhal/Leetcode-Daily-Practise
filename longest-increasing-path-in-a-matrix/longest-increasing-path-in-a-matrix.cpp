class Solution {
public:
    // int dx[4]={0,-1,0,1};
    // int dy[4]={-1,0,1,0};
    // bool isvalid(int x,int y,int m,int n)
    // {
    //     return(x>=0 && x<m && y>=0 && y<n);
    // }
    // int dfs(int i,int j,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& cache)
    // {
    //     if(cache[i][j]!=0)
    //         return cache[i][j];
    //     int ans=1;
    //     for(int k=0;k<4;k++)
    //     {
    //         int newx=i+dx[k];
    //         int newy=j+dy[k];
    //         if(!isvalid(newx,newy,m,n) || matrix[newx][newy]<=matrix[i][j])
    //           continue;
    //         int len=1+dfs(newx,newy,m,n,matrix,cache);
    //         ans=max(ans,len);
    //     }
    //     cache[i][j]=ans;
    //     return ans;
    // }
    // int longestIncreasingPath(vector<vector<int>>& matrix) {
    //     int m=matrix.size();
    //     int n=matrix[0].size();
    //     vector<vector<int>>cache(m,vector<int>(n,0));
    //     int ans=1;
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             int len=dfs(i,j,m,n,matrix,cache);
    //             ans=max(ans,len);
    //         }
    //     }
    //     return ans;
    // }
    
    // topological sort(bfs)
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    bool isvalid(int x,int y,int m,int n)
    {
        return(x>=0 && x<m && y>=0 && y<n);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>indegree(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int len=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 for(int k=0;k<4;k++)
               {
                    int newx=i+dx[k];
                    int newy=j+dy[k];
                    if(isvalid(newx,newy,m,n) && matrix[newx][newy]<matrix[i][j])
                      indegree[i][j]++;
               }
                if(indegree[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        while(!q.empty())
        {
            int siz=q.size();
            for(int i=0;i<siz;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                 for(int k=0;k<4;k++)
                 {
                    int newx=x+dx[k];
                    int newy=y+dy[k];
                    if(isvalid(newx,newy,m,n) && matrix[newx][newy]>matrix[x][y])
                    {
                        indegree[newx][newy]--;
                        if(indegree[newx][newy]==0)
                            q.push(make_pair(newx,newy));
                    }
                 }
            }
            len++;
        }
        return len;
    }
};