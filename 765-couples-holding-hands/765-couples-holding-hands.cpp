class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int>pos(n);
        vector<int>ptn(n);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                ptn[i]=i+1;
            if(i%2==1)
                ptn[i]=i-1;
            pos[row[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=ptn[pos[ptn[row[i]]]];i!=j;j=ptn[pos[ptn[row[i]]]])
            {
                swap(row[i],row[j]);
                swap(pos[row[i]],pos[row[j]]);
                res++;
            }
        }
        return res;
    }
};