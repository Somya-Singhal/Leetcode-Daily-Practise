
class Solution {
public:
    int mod=1e9+7;
    int memo[502][502];
    int len;
    int solve(int i,int steps)
    {
        if(steps==0 && i==0)
            return i==0;
        if(i<0 || i>=len || steps==0 || i>steps)
            return 0;
        if(memo[i][steps]!=-1)
            return memo[i][steps];
        return memo[i][steps]=((solve(i-1,steps-1)%mod+solve(i+1,steps-1))%mod+solve(i,steps-1))%mod;
        
    }
    int numWays(int steps, int arrLen) {
        // memo.resize(steps,vector<int>(steps+1,-1));
        memset(memo,-1,sizeof(memo));
        len=arrLen;
        return solve(0,steps);
    }
    
//      int numWays(int steps, int arrLen) {
        
//         len=arrLen;
//         return solve(0,steps);
//     }
};

    
    