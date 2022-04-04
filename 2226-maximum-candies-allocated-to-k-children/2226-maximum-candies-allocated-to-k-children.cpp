class Solution {
public:
  
    // int maximumCandies(vector<int>& candies, long long k) {
    //     int n=candies.size();
    //     long long sum=0;
    //     for(int i=0;i<n;i++)
    //         sum+=candies[i];
    //     long long lo=0,hi=sum;
    //     while(lo<hi)
    //     {
    //         long long mid=(lo+hi+1)/2,num=0;
    //         for(int i=0;i<n && num<k;i++)
    //         {
    //             num+=candies[i]/mid;
    //         }
    //         if(num>=k)
    //         {
    //             lo=mid;
    //         }
    //         else
    //             hi=mid-1;
    //     }
    //     return lo;
    // }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long sum=0;
        for(int i=0;i<n;i++)
            sum+=candies[i];
        long long lo=1,hi=sum;
        int ans=0;
        while(lo<=hi)
        {
            long long mid=(lo+hi)/2,num=0;;
            for(int i=0;i<n && num<k;i++)
            {
                num+=candies[i]/mid;
            }
            if(num>=k)
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};