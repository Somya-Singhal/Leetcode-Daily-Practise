class Solution {
public:
    // int numPairsDivisibleBy60(vector<int>& time) {
    //     int n=time.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int first=time[i];
    //         for(int j=i+1;j<n;j++)
    //         {
    //             int second=time[j];
    //             if((first+second)%60==0)
    //                 ans++;
    //         }
    //     }
    //     return ans;
    // }
    
     int numPairsDivisibleBy60(vector<int>& time) {
         int n=time.size();
         int ans=0;
         vector<int>v(60,0);
         for(int i=0;i<n;i++)
         {
             time[i]=time[i]%60;
             v[time[i]]++;
         }
         int n1=v[0],n2=v[30];
         ans+=n1*(n1-1)/2;
         ans+=n2*(n2-1)/2;
         for(int i=1;i<=29;i++)
         {
             if(v[i]!=0)
                 if(v[60-i]!=0)
                     ans+=v[i]*v[60-i];
         }
         return ans;
     }
};