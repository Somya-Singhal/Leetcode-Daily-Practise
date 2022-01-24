class Solution {
public:
    // int n,ans=0;
    // bool isvalid(vector<vector<int>>& statements,string& curr)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         if(curr[i]=='1')
    //             for(int j=0;j<n;j++)
    //             {
    //                 if(statements[i][j]!=2 && statements[i][j]!=curr[j]-'0')
    //                     return false;
    //             }
    //     }
    //     return true;
    // }
    // int maximumGood(vector<vector<int>>& statements) {
    //     n=statements.size();
    //     string curr="";
    //     dfs(statements,curr,0,0);
    //         return ans;
    // }
    // void dfs(vector<vector<int>>& statements,string& curr,int i,int cnt)
    // {
    //     if(i==n)
    //     {
    //         if(isvalid(statements,curr))
    //             ans=max(ans,cnt);
    //         return;
    //     }
    //     curr.push_back('0');
    //     dfs(statements,curr,i+1,cnt);
    //     curr.back()='1';
    //     dfs(statements,curr,i+1,cnt+1);
    //     curr.pop_back();
    // }
    int n;
    bool isvalid(vector<vector<int>>& statements,int num)
    {
        for(int i=0;i<n;i++)
        {
            if(num & (1<<i))
            {
                for(int j=0;j<n;j++)
                {
                    if(statements[i][j]!=2 && statements[i][j]!=bool(num & (1<<j)))
                        return false;
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        n=statements.size();
        int ans=0;
        for(int i=1;i<(1<<n);i++)
        {
            if(isvalid(statements,i))
                ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};