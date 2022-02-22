class Solution {
public:
    // unordered_map<string,bool>mp;
    // bool solve(string s1,string s2)
    // {
    //     if(s1.compare(s2)==0)
    //         return true;
    //     if(s1.length()<=1)
    //         return false;
    //     string key=s1;
    //     key.push_back(' ');
    //     key.append(s2);
    //     if(mp.find(key)!=mp.end())
    //         return mp[key];
    //     int n=s1.length();
    //     bool flag=false;
    //     for(int i=1;i<=n-1;i++)
    //     {
    //         if((solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i))) || (solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i))))
    //         {
    //             flag=true;
    //             break;
    //         }
    //     }
    //     return mp[key]=flag;
    // }
    // bool isScramble(string s1, string s2) {
    //     int n1=s1.length();
    //     int n2=s2.length();
    //     if(n1-n2)
    //         return false;
    //     if(n1==0 && n2==0)
    //         return true;
    //     return solve(s1,s2);
    // }
    
    bool isScramble(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        if(n1!=n2)
            return false;
        if(n1==1)
            return s1==s2;
        bool dp[n1][n1][n1+1];
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                for(int k=0;k<=n1;k++)
                    dp[i][j][k]=false;
            }
        }
        for(int k=1;k<=n1;k++)
        {
            for(int i=0;i+k<=n1;i++)
            {
                for(int j=0;j+k<=n1;j++)
                {
                    if(k==1)
                      dp[i][j][k]=s1[i]==s2[j];
                    else 
                    for(int q=1;q<k && !dp[i][j][k];q++)
                      dp[i][j][k]=(dp[i][j][q] && dp[i+q][j+q][k-q]) || (dp[i][j+k-q][q] && dp[i+q][j][k-q]);
                }
            }
        }
        return dp[0][0][n1];
    }
};