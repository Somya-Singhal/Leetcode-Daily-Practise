class Solution {
public:
    // int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight)     {
    //     int n=boxes.size();
    //     vector<int>difficult(n+1,0),wt(n+1,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         difficult[i+1]=difficult[i]+(i!=0 && boxes[i][0]==boxes[i-1][0]?0:1);
    //         wt[i+1]=wt[i]+boxes[i][1];
    //     }
    //     vector<int>dp(n+1,INT_MAX);
    //     dp[0]=0;
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=i-1;j>=0;j--)
    //         {
    //             int change=difficult[i]-difficult[j+1];
    //             int weight=wt[i]-wt[j];
    //             int b=i-j;
    //             if(b<=maxBoxes && weight<=maxWeight)
    //             {
    //                 dp[i]=min(dp[i],2+change+dp[j]);
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
    
     int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight)     {
        int n=boxes.size();
        vector<long long>difficult(n+1,0),wt(n+1,0);
        for(int i=0;i<n;i++)
        {
            difficult[i+1]=difficult[i]+(i!=0 && boxes[i][0]==boxes[i-1][0]?0:1);
            wt[i+1]=wt[i]+boxes[i][1];
        }
        vector<long long>dp(n+1,LONG_LONG_MAX);
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>>pq;
        pq.push({-1,0}); 
        for(int i=1;i<=n;i++)
        {
            while(!pq.empty() && ((i-pq.top().second)>maxBoxes || (wt[i]-wt[pq.top().second])>maxWeight))
                pq.pop();
            dp[i]=2+pq.top().first+difficult[i];
            if(i!=n)
            {
                pq.push({dp[i]-difficult[i+1],i});
            }
        }
        return dp[n];
    }
};