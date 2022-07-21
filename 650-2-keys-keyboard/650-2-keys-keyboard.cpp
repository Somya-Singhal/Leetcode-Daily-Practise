class Solution {
public:
    int solve(int i,int copy,int n)
    {
        if(i>n)
            return 1000000;
        if(i==n)
            return 0;
        
        return min(1+solve(i+copy,copy,n),2+solve(i+i,i,n));
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        return 1+solve(1,1,n);
    }
};