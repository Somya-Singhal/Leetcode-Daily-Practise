class Solution {
public:
    // vector<int> countBits(int n) {
    //     vector<int>res(n+1,0);
    //     for(int i=1;i<=n;i++)
    //     {
    //         int temp=i,count=0;
    //         while(temp>0)
    //         {
    //             if(temp & 1 !=0)
    //                count++;
    //             temp=temp>>1;
    //         }
    //         res[i]=count;
    //     }
    //     return res;
    // }
     vector<int> countBits(int n) {
        vector<int>res(n+1,0);
         int offset=1;
        for(int i=1;i<=n;i++)
        {
            if(offset*2==i)
                offset*=2;
            res[i]=res[i-offset]+1;
        }
        return res;
         }
};