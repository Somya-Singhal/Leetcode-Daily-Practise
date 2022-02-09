class Solution {
public:
    //binary search on each boxes array
    int mod=1e9+7;
    // int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    //     int n=packages.size();
    //     int m=boxes.size();
    //     sort(packages.begin(),packages.end());
    //     long ans=LONG_MAX;
    //     for(int i=0;i<m;i++)
    //     {
    //         sort(boxes[i].begin(),boxes[i].end());
    //         int j;
    //         long spaceWasted=0;
    //         for(j=0;j<n;j++)
    //         {
    //             int lo=0,hi=boxes[i].size()-1;
    //             long currSpace=LONG_MIN;
    //             while(lo<=hi)
    //             {
    //                 int mid=(lo+hi)/2;
    //                 if(boxes[i][mid]==packages[j])
    //                 {
    //                     currSpace=0;
    //                     break;
    //                 }
    //                 else if(boxes[i][mid]>packages[j])
    //                 {
    //                     currSpace=boxes[i][mid]-packages[j];
    //                     hi=mid-1;
    //                 }
    //                 else
    //                     lo=mid+1;
    //             }
    //             if(currSpace==LONG_MIN)
    //                 break;
    //             spaceWasted+=currSpace;
    //         }
    //         if(j<=n-1)
    //             continue;
    //         ans=min(ans,spaceWasted%mod);
    //         // cout<<ans<<" ";
    //     }
    //     return ans==LONG_MAX?-1:ans%mod;
    // }
    
     int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n=packages.size();
        int m=boxes.size();
        long presum=0;
        sort(packages.begin(),packages.end());
         for(int i=0;i<n;i++)
             presum+=packages[i];
        long ans=LONG_MAX;
        for(int i=0;i<m;i++)
        {
            sort(boxes[i].begin(),boxes[i].end());
            long spaceWasted=0,prev=0;
            if(packages[n-1]>boxes[i][boxes[i].size()-1])
                    continue;
            for(int j=0;j<boxes[i].size();j++)
            {
                long lo=0,hi=n;
                while(lo<hi)
                {
                    long mid=(lo+hi)/2;
                    if(packages[mid]>boxes[i][j])
                        hi=mid;
                    else
                        lo=mid+1;
                }
                spaceWasted+=boxes[i][j]*(lo-prev);
                prev=lo;
            }
            ans=min(ans,spaceWasted);
        }
         return ans==LONG_MAX?-1:(int)((ans-presum)%mod);
     }
};