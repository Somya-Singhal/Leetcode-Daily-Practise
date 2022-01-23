class Solution {
public:
    //bfs and min-heap(item with lower price-->higher rank)
    int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>res;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[start[0]][start[1]]=true;
        q.push(make_pair(start[0],start[1]));
        while(q.size() && res.size()<k)
        {
            int len=q.size();
            vector<vector<int>>temp;
            while(len--)
            {
                auto [x,y]=q.front();
                q.pop();
                if(grid[x][y]>=pricing[0] && grid[x][y]<=pricing[1])
                temp.push_back({grid[x][y],x,y});
                 for(auto &[dx,dy]:dir)
                    {
                        int newx=dx+x;
                        int newy=dy+y;
                        if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]!=0 && !vis[newx][newy])
                        {
                       
                                q.push(make_pair(newx,newy));
                                 vis[newx][newy]=true;
                        }
                    }
            }
            sort(temp.begin(),temp.end());
            for(auto t: temp)
            {
                res.push_back({t[1],t[2]});
                if(res.size()==k)
                    break;
            }
        }
        
        return res;
    }
};