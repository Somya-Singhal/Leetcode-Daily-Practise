class Solution {
public:
    void solve(int n,int k,string curr,vector<int>& res)
    {
        if(curr[0]=='0')
            return;
        if(curr.length()==n)
        {
            int num=stoi(curr);
            res.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++)
        {
            if(curr.length()==0)
                solve(n,k,to_string(i),res);
            else {
            int t=curr[curr.length()-1]-'0';
            if(abs(i-t)==k)
                solve(n,k,curr+to_string(i),res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        solve(n,k,"",res);
        return res;
    }
};