class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>ans;
        int startcol=0,endcol=col-1;
        while(startcol<=endcol)
        {
            int maxrow=0;
            int midcol=startcol+(endcol-startcol)/2;
            for(int i=0;i<row;i++)
            {
                maxrow=mat[i][midcol]>=mat[maxrow][midcol]?i:maxrow;
            }
            bool isLeftBig=(midcol-1>=startcol) && (mat[maxrow][midcol-1]>mat[maxrow][midcol]);
            bool isRightBig=(midcol+1<=endcol) && (mat[maxrow][midcol+1]>mat[maxrow][midcol]);
            if(!isLeftBig && !isRightBig)
            {
                return vector<int>{maxrow,midcol};
            }
            else if(isRightBig)
                startcol=midcol+1;
            else
                endcol=midcol-1;
        }
        return vector<int>{-1,-1};
    }
};