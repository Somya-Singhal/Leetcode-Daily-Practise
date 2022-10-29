class Solution {
public:
    int arrangeCoins(int n) {
        int count=0,left=n;
        for(int i=1;i<=n;i++)
        {
            if(left-i<0)
                break;
            count++;
            left-=i;
        }
        return count;
    }
};