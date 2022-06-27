class Solution {
public:
    pair<int,int>intToRC(int sq,int len)
    {
        int r=(sq-1)/len;
        int c=(sq-1)%len;
        if(r%2)
            c=len-1-c;
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        reverse(board.begin(),board.end());
        queue<pair<int,int>>q;
        vector<int>vis(n*n,0);
        q.push({1,0});
        vis[1]=1;
        while(!q.empty())
        {
            int sqaure=q.front().first;
            int moves=q.front().second;
            q.pop();
            for(int i=1;i<=6;i++)
            {
                int nextmove=sqaure+i;
                pair<int,int>p=intToRC(nextmove,n);
                int r=p.first,c=p.second;
                if(board[r][c]!=-1)
                    nextmove=board[r][c];
                if(nextmove==n*n)
                    return moves+1;
                if(!vis[nextmove])
                {
                    vis[nextmove]=1;
                    q.push({nextmove,moves+1});
                }
            }
        }
        return -1;
    }
};