class Solution {
public:
    long long cache[501][501]={0};
    int mod=1e9+7;
    long long solve(int unpicked,int undelivered)
    {
        if(unpicked==0 && undelivered==0)
            return 1;
        if(unpicked>undelivered || undelivered<0 || unpicked<0)
            return 0;
        if(cache[unpicked][undelivered]!=0)
            return cache[unpicked][undelivered];
        long long pickways=unpicked*solve(unpicked-1,undelivered)%mod;
        long long deliveredways=(undelivered-unpicked)*solve(unpicked,undelivered-1)%mod;
        return cache[unpicked][undelivered]=pickways+deliveredways;
    }
    int countOrders(int n) {
       return solve(n,n); 
    }
};