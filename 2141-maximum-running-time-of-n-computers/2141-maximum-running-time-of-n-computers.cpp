class Solution {
public:
    // bool isTrue(vector<int>& batteries,long long t,int computers) {
    //     int n=batteries.size();
    //     long long sum=0;
    //     for(int i=0;i<n;i++){
    //         if(batteries[i]<=t)
    //             sum+=batteries[i];
    //         else
    //             sum+=t;
    //     }
    //     return sum>=computers*t;
    // }
    // long long maxRunTime(int n, vector<int>& batteries) {
    //     int len=batteries.size();
    //     long long sum=0,ans=0;
    //     for(int i=0;i<len;i++)
    //     {
    //         sum+=batteries[i];
    //     }
    //     long long lo=0,hi=sum;
    //     while(lo<=hi){
    //         long long maxTime=(lo+hi)/2;
    //         if(isTrue(batteries,maxTime,n)){
    //             ans=maxTime;
    //             lo=maxTime+1;
    //         } else{
    //             hi=maxTime-1;
    //         }
    //     }
    //     return ans;
    // }
    
     long long maxRunTime(int n, vector<int>& batteries) {
        int len=batteries.size();
        sort(batteries.begin(),batteries.end());
        long long sum=0,ans=0;
        for(int i=0;i<len;i++)
        {
            sum+=batteries[i];
        }
        int l=0;
        while(batteries[len-1-l]>sum/(n-l))
        {
            sum-=batteries[len-1-l++];
        }
         return sum/(n-l);
    }
};