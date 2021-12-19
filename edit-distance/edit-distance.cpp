class Solution {
public:
    // int Distrec(int i,int j,string word1,string word2)
    // {
    //     if(word1.length()==i)
    //         return word2.length()-j;
    //     if(word2.length()==j)
    //         return word1.length()-i;
    //     if(word1[i]==word2[j])
    //         return Distrec(i+1,j+1,word1,word2);
    //     else
    //         return 1+min(min(Distrec(i,j+1,word1,word2),Distrec(i+1,j,word1,word2)),Distrec(i+1,j+1,word1,word2));
    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     return Distrec(0,0,word1,word2);
    // }
     int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else
                {
                    if(word1[i-1]==word2[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
                }
            }
        }
         return dp[n][m];
    }
};