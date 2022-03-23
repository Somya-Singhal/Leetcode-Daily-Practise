class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    // int DIR[5] = {0, 1, 0, -1, 0};
   
    bool bfs(int r,int c,vector<vector<int>>& grid,int row,int col)
    {
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]=1;
         while(!q.empty())
        {
           int x=q.front().first,y=q.front().second;
            q.pop();
            if(x==row-1)
                return true;
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i],newy=y+dy[i];
                if( newx<0 || newx==row || newy<0 || newy==col || grid[newx][newy]==1)
                    continue;
                grid[newx][newy]=1;
                q.push({newx,newy});
            }
        }
        return false;
    }
    
    bool solve(vector<vector<int>>& cells,int row,int col,int mid)
    {
        vector<vector<int>>grid(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0;i<mid;i++)
        {
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        for(int i=0;i<col;i++)
        {
            if(grid[0][i]==0 && bfs(0,i,grid,row,col))
            return true;
        }
       return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int lo=1,hi=n;
        int lastDay=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(solve(cells,row,col,mid))
            {
                 lastDay=mid;
                 lo=mid+1;
               
            }
            else{
                hi=mid-1;
            }
        }
        return lastDay;
    }
};