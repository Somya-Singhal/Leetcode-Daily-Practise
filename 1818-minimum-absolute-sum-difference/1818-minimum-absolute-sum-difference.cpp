class Solution {
public:
    int mod=1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        long j,currmin,curr,sum=0;
        vector<long>diff(n,0),v(n,0);
        for(int i=0;i<n;i++)
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            sum+=diff[i];
        }
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++)
        {
           int lo=0,hi=n-1;
            int small=nums1[0],large=nums1[n-1];
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;
                if(nums1[mid]==nums2[i])
                {
                    small=nums1[mid];
                    large=nums1[mid];
                    break;
                }
                else if(nums1[mid]<nums2[i])
                {
                    small=nums1[mid];
                    lo=mid+1;
                }
                else
                {
                    large=nums1[mid];
                    hi=mid-1;
                }
            }
            currmin=min(abs(small-nums2[i]),abs(large-nums2[i]));
            v[i]=currmin;
        }
        long ans=LONG_MAX;
        for(int i=0;i<n;i++)
        {
            long temp=(sum-diff[i]+v[i]);
            ans=min(ans,temp);
        }
        return ans%mod;
    }
};