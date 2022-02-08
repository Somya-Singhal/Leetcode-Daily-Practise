class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        int d=int(log(num)/log(10))+1;
        if(d==1)
            return num;
        int ans=0;
        while(num>0)
        {
            int a=num%10;
            num=num/10;
            ans+=a;
        }
        return addDigits(ans);
    }
};