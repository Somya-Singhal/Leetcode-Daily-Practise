class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       long long sum=0;
        int ans=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            sum+=piles[i];
        }
        long long lo=1,hi=sum;
        while(lo<=hi){
           long long mid=(lo+hi)/2,count=0;
            for(int i=0;i<n;i++)
            {
                count+=piles[i]/mid+(piles[i]%mid?1:0);
            }
            if(count<=h)
            {
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};