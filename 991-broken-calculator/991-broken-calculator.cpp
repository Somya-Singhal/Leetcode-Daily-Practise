class Solution {
public:
    
    int brokenCalc(int startValue, int target) {
        int count=0,y=target;
       while(y!=startValue)
       {
           if(startValue>=y)
               return (startValue-y)+count;
           if(y%2==0)
               y=y/2;
           else
               y++;
           count++;
       }
        return count;
    }
};