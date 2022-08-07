class Solution {
public:
    int mod=1e9+7;
    int dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={1,2,2,1,-1,-2,-2,-1};
    int memo[5][4][5001];
    int solve(int x,int y,char grid[4][3],int n)
    {
        if(x<0 || x>3 || y<0 || y>2 || grid[x][y]=='#' || grid[x][y]=='*')
            return 0;
        if(n==1)
            return 1;
        if(memo[x][y][n]!=0)
            return memo[x][y][n];
        int ways=0;
        for(int i=0;i<8;i++)
        {
            ways=(ways+solve(x+dx[i],y+dy[i],grid,n-1))%mod;
        }
        memo[x][y][n]=ways;
        return memo[x][y][n];
    }
    int knightDialer(int n) {
        
        memset(memo,0,sizeof(memo));
        char grid[4][3]={'1','2','3',
                         '4','5','6',
                         '7','8','9',
                         '*','0','#'
                        };
        int ways=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                ways=(ways+solve(i,j,grid,n))%mod;
            }
        }
        return ways;
    }
};