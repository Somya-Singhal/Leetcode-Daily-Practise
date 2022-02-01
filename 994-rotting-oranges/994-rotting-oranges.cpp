class Solution {
public:
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     int count=0;
    //     queue<pair<int,int>>q;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==2)
    //                 q.push(make_pair(i,j));
    //         }
    //     }
    //     //bfs
    //     int dirx[4]={0,-1,0,1};
    //     int diry[4]={-1,0,1,0};              
    //     while(!q.empty())
    //     {
    //         int len=q.size();
    //         for(int i=0;i<len;i++)
    //         {
    //             int x=q.front().first;
    //             int y=q.front().second;
    //             q.pop();
    //             for(int j=0;j<4;j++)
    //             {
    //                 int newx=x+dirx[j];
    //                 int newy=y+diry[j];
    //                 if(newx<0 || newy<0 || newx>=n || newy>=m || grid[newx][newy]==0 || grid[newx][newy]==2)
    //                     continue;
    //                else
    //                 {
    //                         grid[newx][newy]=2;
    //                         q.push(make_pair(newx,newy));
    //                 }
    //             }
    //         }
    //         count++;
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==1)
    //                 return -1;
    //         }
    //     }
    //     return (count>0)?count-1:0;
    // }
    
    //some optimization
     int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh_oranges=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push(make_pair(i,j));
                if(grid[i][j]==1)
                  fresh_oranges++;  
            }
        }
         if(fresh_oranges==0)
             return 0;
        //bfs
         int count=0;
        int dirx[4]={0,-1,0,1};
        int diry[4]={-1,0,1,0};              
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int newx=x+dirx[j];
                    int newy=y+diry[j];
                    if(newx<0 || newy<0 || newx>=n || newy>=m || grid[newx][newy]==0 || grid[newx][newy]==2)
                        continue;
                   else
                    {
                            grid[newx][newy]=2;
                            q.push(make_pair(newx,newy));
                            fresh_oranges--;
                    }
                }
            }
            count++;
        }
        return (fresh_oranges==0)?count-1:-1;
    }
};