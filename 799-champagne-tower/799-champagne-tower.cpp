class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double filled[101][100]={0.0};
        filled[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(filled[i][j]>=1)
                {
                    filled[i+1][j]+=(filled[i][j]-1)/2.0;
                    filled[i+1][j+1]+=(filled[i][j]-1)/2.0;
                    filled[i][j]=1;
                }
            }
        }
        return filled[query_row][query_glass];
    }
};