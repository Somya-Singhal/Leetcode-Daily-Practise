class Solution {
public:
    void solve(int i,int n,int k,unordered_set<int>& s)
    {
        if(n==0)
        {
            s.insert(i);
            return;
        }
        if((i%10)+k<=9)
            solve(i*10+(i%10)+k,n-1,k,s);
        if((i%10)-k>=0)
            solve(i*10+(i%10)-k,n-1,k,s); 
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int>s;
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            solve(i,n-1,k,s);
        }
        for(auto x: s)
            ans.push_back(x);
        return ans;
    }
};