class Solution {
public:
//     int solve(int i,int copy,int n)
//     {
//         if(i>n)
//             return 1000000;
//         if(i==n)
//             return 0;
        
//         return min(1+solve(i+copy,copy,n),2+solve(i+i,i,n));
//     }
//     int minSteps(int n) {
//         if(n==1)
//             return 0;
//         return 1+solve(1,1,n);
//     }
    
    
//     int minSteps(int n) {

//         vector<int>dp(n+1,0);
//         for(int i=2;i<=n;i++)
//         {
//             dp[i]=i;
//             for(int j=i-1;j>1;j--)
//             {
//                 if(i%j==0)
//                 {
//                     dp[i]=dp[j]+(i/j);
//                     break;
//                 }
                    
//             }
//         }
//         return dp[n];
//     }
    
     int minSteps(int n) {
         int res=0;
        
        for(int i=2;i<=n;i++)
        {
            while(n%i==0)
            {
                res+=i;
                n=n/i;
            }
        }
        return res;
    }
};