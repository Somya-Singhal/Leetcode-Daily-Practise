class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    if(dungeon[i][j]>0)
                        dungeon[i][j]=0;
                }
                else if(i==n-1)
                {
                    int temp=dungeon[i][j]+dungeon[i][j+1];
                    if(temp>=0)
                       dungeon[i][j]=0;
                    else
                      dungeon[i][j]=temp;  
                }
                else if(j==m-1)
                {
                    int temp=dungeon[i][j]+dungeon[i+1][j];
                    if(temp>=0)
                       dungeon[i][j]=0;
                    else
                      dungeon[i][j]=temp;  
                }
                else
                {
                       int temp=max(dungeon[i+1][j],dungeon[i][j+1]);
                       if(dungeon[i][j]+temp>=0)
                           dungeon[i][j]=0;
                       else
                           dungeon[i][j]+=temp;
                }
            }
        }
        return abs(dungeon[0][0])+1;
    }
};