class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>res;
        int row=grid.size(),col=grid[0].size();
        for(int c=0;c<col;c++)
        {
            int i1=c,i2;
            for(int r=0;r<row;r++)
            {
                i2=i1+grid[r][i1];
                if(i2<0 || i2>=col || grid[r][i1]!=grid[r][i2])
                {
                    i1=-1;
                    break;
                }
                i1=i2;
            }
           res.push_back(i1); 
        }
        return res;
    }
};