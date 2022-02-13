class Solution {
public:
    int count=0;
    void solve(int val,int n,vector<int>& v)
    {
        if(val>n)
        {
            count++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0 && (val%i==0 || i%val==0))
            {
                v[i]=val;
                solve(val+1,n,v);
                v[i]=0; 
            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1,0);
        solve(1,n,v);
        return count;
    }
};