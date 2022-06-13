class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool valid(int x,int y,int cr,int cc,vector<vector<int>>& img,int m,int n)
    {
        return (x>=0 && x<m && y>=0 && y<n && img[x][y]==img[cr][cc]);
    }
    void solve(int sr, int sc, int newColor,vector<vector<int>>& img,vector<vector<int>>& res,vector<vector<bool>>& vis)
    {
        int m=img.size(),n=img[0].size();
        queue<pair<int,int>>q;
        vis[sr][sc]=true;
        q.push({sr,sc});
        res[sr][sc]=newColor;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(valid(newx,newy,x,y,img,m,n) && !vis[newx][newy])
                {
                    vis[newx][newy]=true;
                    res[newx][newy]=res[x][y];
                    q.push({newx,newy});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>>res=image;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        solve(sr,sc,newColor,image,res,vis);
        return res;
    }
};