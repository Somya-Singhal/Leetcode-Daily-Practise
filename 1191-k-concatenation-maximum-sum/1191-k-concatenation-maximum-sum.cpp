class Solution {
public:
    int mod=1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        int maxsum=arr[0],currsum=arr[0];
        //case-1: applykahns algo
        if(k==1)
        {
            for(int i=1;i<n;i++)
            {
                currsum=max(arr[i],arr[i]+currsum);
                currsum=currsum%mod;
                maxsum=max(maxsum,currsum);
                maxsum=maxsum%mod;
            }
            return maxsum%mod;
        }
        
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        sum=sum;
        //case-2: sum<0(apply kahns by concatenating only 2 array,ans will be found)
            vector<long long>temp;
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<n;j++)
                {
                    temp.push_back(arr[j]);
                }
            }
            for(long long i=1;i<2*n;i++)
            {
                currsum=max(temp[i],temp[i]+currsum);
                currsum=currsum;
                maxsum=max(maxsum,currsum);
                maxsum=maxsum;
            }
        if(maxsum<0 && sum<=0)
            return 0;
        if(sum<=0)
            return maxsum%mod;
        
        return (maxsum%mod+((k-2)*sum)%mod)%mod;
    }
};