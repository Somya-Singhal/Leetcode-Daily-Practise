class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=matchsticks[i];
        if(sum%4)
            return false;
        int sideLen=sum/4;
        int total=(1<<n)-1;
        vector<bool>validHalfset(1<<n,false);
        vector<int>usedMask;
        for(int mask=0;mask<=total;mask++)
        {
            long subsetSum=0;
            for(int i=0;i<32;i++)
            {
                if((mask>>i)&1)
                   subsetSum+=matchsticks[i]; 
            }
            if(subsetSum==sideLen)
            {
                for(int used: usedMask){
                    if((used & mask)==0)
                    {
                        int validHalf=used|mask;
                        validHalfset[validHalf]=true;
                        if(validHalfset[total^validHalf])
                            return true;
                    }
                }
                usedMask.push_back(mask);
            }
        }
        return false;
    }
};