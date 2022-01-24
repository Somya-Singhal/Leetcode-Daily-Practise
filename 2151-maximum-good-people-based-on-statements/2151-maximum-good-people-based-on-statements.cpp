class Solution {
public:
    int n,ans=0;
    bool isvalid(vector<vector<int>>& statements,string& curr)
    {
        for(int i=0;i<n;i++)
        {
            if(curr[i]=='1')
                for(int j=0;j<n;j++)
                {
                    if(statements[i][j]!=2 && statements[i][j]!=curr[j]-'0')
                        return false;
                }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        n=statements.size();
        string curr="";
        dfs(statements,curr,0,0);
            return ans;
    }
    void dfs(vector<vector<int>>& statements,string& curr,int i,int cnt)
    {
        if(i==n)
        {
            if(isvalid(statements,curr))
                ans=max(ans,cnt);
            return;
        }
        curr.push_back('0');
        dfs(statements,curr,i+1,cnt);
        curr.back()='1';
        dfs(statements,curr,i+1,cnt+1);
        curr.pop_back();
    }
};