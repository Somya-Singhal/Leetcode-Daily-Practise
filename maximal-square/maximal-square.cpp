class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxside_len=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    int side_len=1;
                    bool flag=true;
                    while(side_len+i<n && side_len+j<m && flag)
                    {
                        for(int k=j;k<=side_len+j;k++)
                        {
                            if(matrix[i+side_len][k]=='0')
                            {
                                flag=false;
                                break;
                            }
                        }
                        for(int k=i;k<=side_len+i;k++)
                        {
                            if(matrix[k][j+side_len]=='0')
                            {
                                flag=false;
                                break;
                            }
                        }
                        if(flag)
                            side_len++;
                    }
                    if(maxside_len<side_len)
                            maxside_len=side_len;
                }
            }
        }
        return maxside_len*maxside_len;
    }
};