class Solution {
public:
    // int nthSuperUglyNumber(int n, vector<int>& primes) {
    //     int m=primes.size();
    //     vector<int>pointer(m,0);
    //     vector<int>dp(n,0);
    //     dp[0]=1;
    //     for(int i=1;i<n;i++)
    //     {
    //         int currmin=INT_MAX;
    //         for(int j=0;j<m;j++)
    //         {
    //             currmin=min(currmin,primes[j]*dp[pointer[j]]);
    //         }
    //         dp[i]=currmin;
    //         for(int j=0;j<m;j++)
    //         {
    //             if(primes[j]*dp[pointer[j]]<=dp[i])
    //                 pointer[j]++;
    //         }
    //     }
    //     return dp[n-1];
    // }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len=primes.size();
        vector<long long int>dp(n,0);
        map<long long int,pair<long long int,long long int>>m;
        dp[0]=1;
       for(int i=0;i<len;i++)
       {
           m.insert({primes[i],make_pair(0,primes[i])});
       }
        int i=1;
        while(i<n)
        {
            auto it=m.begin();
            long long int num=it->first;
            pair<long long int,long long int>p=it->second;
            long long int pointer=p.first;
            long long int prime=p.second;
            m.erase(it);
            if(num!=dp[i-1])
            {
                dp[i]=num;
                i++;
            }
            while(m.find(prime*dp[++pointer])!=m.end());
            long long int newnum=prime*dp[pointer];
            m.insert({newnum,make_pair(pointer,prime)});
        }
        return dp[n-1];
    }
};