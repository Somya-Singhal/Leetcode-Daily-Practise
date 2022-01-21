class Solution {
public:
    // int countNumbersWithUniqueDigits(int n) {
    //     int count=0;
    //     for(int i=0;i<pow(10,n);i++)
    //     {
    //         vector<int>dp(10,0);
    //         int num=i;
    //         bool flag=false;
    //         while(num>0)
    //         {
    //             int digit=num%10;
    //             if(dp[digit]!=0)
    //             {
    //                 flag=true;
    //                 break;
    //             }    
    //             dp[digit]++;
    //             num=num/10;
    //         }
    //         if(flag==false)
    //             count++;
    //     }
    //     return count;
    // }
     int countNumbersWithUniqueDigits(int n) {
         if(n==0)
             return 1;
         int currcount=9,ans=10,uniquedigit=9;
         for(int i=2;i<=n;i++)
         {
             uniquedigit*=currcount;
             ans+=uniquedigit;
             currcount--;
         }
        return ans;
    }
};