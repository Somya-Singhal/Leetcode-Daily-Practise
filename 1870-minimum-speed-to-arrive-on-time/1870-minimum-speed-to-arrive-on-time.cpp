class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
       long lo=1,hi;
        double max_total=LONG_MIN;
        int n=dist.size(),ans=-1;
        if(hour<n-1)
            return -1;
        for(int i=0;i<n;i++){
            max_total=max(max_total,hour*dist[i]);
        }
        while(lo<=hi){
            long mid=(lo+hi)/2;
            double t=0;
            for(int i=0;i<n;i++){
                t=ceil(t);
                t+=(double)dist[i]/mid;
            }
            if(t<=hour){
                ans=mid;
                // cout<<ans<<" ";
                hi=mid-1;
            } else{
                lo=mid+1;
            }
        }
        return ans;
    }
};