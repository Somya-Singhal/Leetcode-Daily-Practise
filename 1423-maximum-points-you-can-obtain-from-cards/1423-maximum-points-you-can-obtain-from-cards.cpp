class Solution {
public:
   
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxsum=INT_MIN;
        vector<int>spre(n+1,0),bpre(n+1,0);
        spre[0]=0;
        bpre[n]=0;
        for(int i=1;i<=n;i++)
        {
            spre[i]=cardPoints[i-1]+spre[i-1];
            bpre[n-i]=bpre[n-i+1]+cardPoints[n-i];
        }
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<spre[i]<<" ";
        // }
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<bpre[i]<<" ";
        // }
        for(int i=0;i<=k;i++)
        {
            maxsum=max(maxsum,spre[i]+bpre[n-k+i]);
        }
        return maxsum;
    }
};