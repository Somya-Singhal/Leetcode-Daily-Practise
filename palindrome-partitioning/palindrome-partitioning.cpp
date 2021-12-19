class Solution {
public:
    
    //recursive--->(n*2^n) Space->O(n)
    // bool isvalid(int i,int j,string s)
    // {
    //     while(i<=j)
    //     {
    //       if(s[i]!=s[j])
    //           return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // void partitionrec(int i,int j,string s,vector<string>& v,vector<vector<string>>& res)
    // {
    //     if(i==s.length())
    //     {
    //          res.push_back(v);
    //          return;
    //     }
    //     for(int k=i;k<j;k++)
    //     {
    //         if(isvalid(i,k,s))
    //         {
    //             v.push_back(s.substr(i,k-i+1));
    //             partitionrec(k+1,j,s,v,res); 
    //             v.pop_back();
    //         }
    //     }
    //     return;
    // }
    // vector<vector<string>> partition(string s) {
    //     vector<vector<string>>res;
    //     vector<string>v;
    //     int n=s.length();
    //     partitionrec(0,n,s,v,res);
    //     return res;
    // }
    
    //dp
    void partitionrec(int i,int j,string s,vector<string>& v,vector<vector<string>>& res,vector<vector<bool>>& dp)
    {
        if(i==s.length())
        {
             res.push_back(v);
             return;
        }
        for(int k=i;k<j;k++)
        {
            if(s[i]==s[k] && (k-i<=2 || dp[i+1][k-1]))
            {
                dp[i][k]=true;
                v.push_back(s.substr(i,k-i+1));
                partitionrec(k+1,j,s,v,res,dp); 
                v.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        partitionrec(0,n,s,v,res,dp);
        return res;
    }
};