class Solution {
public:
    int mod=1e9+7;
    unordered_map<string,int>memo;
    int solve(char prev,int n)
    {
        if(n==0)
            return 1;
        string str=to_string(prev)+" "+to_string(n);
        if(memo.find(str)!=memo.end())
            return memo[str];
        if(prev=='a')
            return memo[str]=solve('e',n-1)%mod;
        if(prev=='e')
            return memo[str]=(solve('a',n-1)+solve('i',n-1))%mod;
        if(prev=='i')
            return memo[str]=((solve('a',n-1)+solve('e',n-1))%mod+(solve('o',n-1)+solve('u',n-1))%mod)%mod;
        if(prev=='o')
            return memo[str]=(solve('i',n-1)+solve('u',n-1))%mod;
            
        return memo[str]=solve('a',n-1)%mod;
    
    }
    int countVowelPermutation(int n) {
       
        return ((((solve('a',n-1)%mod+solve('e',n-1)%mod)%mod+solve('i',n-1)%mod)%mod+solve('o',n-1)%mod)%mod+solve('u',n-1)%mod)%mod;
    }
};