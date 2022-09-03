class Solution {
public:
    int divide(int dividend, int divisor) {
        if((dividend==INT_MIN && divisor==-1) || (dividend==INT_MAX && divisor==1))
            return INT_MAX;
        if((dividend==INT_MIN && divisor==1) || (dividend==INT_MIN && divisor==-1))
            return INT_MIN;
        bool sign=((dividend>0) == (divisor>0))?true:false;
        int res=0;
        long diva=abs(dividend),divb=abs(divisor);
        while(diva-divb>=0)
        {
            int count=0;
            while(diva-(divb<<1<<count)>=0)
                count++;
            res+=1<<count;
            diva-=divb<<count;
        }
        return sign?res:-res;
        
    }
};