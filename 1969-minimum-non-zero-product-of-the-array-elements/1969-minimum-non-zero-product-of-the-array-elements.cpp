class Solution {
public:
    long long MOD=1e9+7;
    int modpow(long long val,long long pairs)
    {
        if(pairs==0)
            return 1;
        long long t=modpow(val,pairs/2);
        t=(t*t)%MOD;
        return pairs%2?(t*(val%MOD))%MOD:t;
    }
    int minNonZeroProduct(int p) {
        long long num=(1ll<<p)-1;
        long long val=num-1;
        return num%MOD*modpow(val,val/2)%MOD;
    }
};