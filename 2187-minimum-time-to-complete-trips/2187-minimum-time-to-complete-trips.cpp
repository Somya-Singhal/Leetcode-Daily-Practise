class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long lo=1;
        int n=time.size();
        sort(time.begin(),time.end());
        long long hi=1e14;
        long long timeTaken=0;
        while(lo<hi)
        {
            long long mid=(lo+hi)/2;
            long long coveredTrips=0;
            for(int i=0;i<n;i++)
            {
                long long val=time[i];
               coveredTrips+=mid/val;
            }
            if(coveredTrips>=totalTrips)
               {
                   hi=mid;
               }
            else
                lo=mid+1;
        }
        return lo;
    }
};