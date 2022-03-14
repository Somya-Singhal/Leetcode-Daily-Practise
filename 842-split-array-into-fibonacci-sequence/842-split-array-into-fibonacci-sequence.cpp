class Solution {
public:
     bool solve(int idx,string num,vector<int>& res)
    {
        if(idx>=num.length() && res.size()>=3)
        {
            return true;
        }
         long n=0;
        for(int i=idx;i<num.length();i++)
        {
            if(num[idx]=='0' && i>idx)
            return false;
            n=n*10+num[i]-'0';
            // s>>n;
            if(n>INT_MAX)
            return false;
            int len=res.size();
            // long mysum=res[len-1]+res[len-2];
            if(len>=2 && n>(long)res[len-1]+res[len-2])
            return false;
                
            if(len<=1 || n==(long)res[len-1]+res[len-2])
            {
                res.push_back((int)n);
                if(solve(i+1,num,res)==true)
                {
                    return true;
                }
                res.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int>res;
        solve(0,num,res);
        return res;
    }
};