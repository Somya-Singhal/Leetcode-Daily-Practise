class Solution {
public:
    // recursive solution-> for learning purpose
   /* bool palindrome(string op,int i,int j)
    {
        if(i>=j)
            return true;
        return (op[i]==op[j])?palindrome(op,i+1,j-1):false;
    }
    int count=0,len=0,maxlen=0;
    void countrec(string s,int index,int n,string op)
    {
        if(index==n)
        {
         len++;
         return;   
        }
        else
        {
            for(int i=index;i<n;i++)
            {
                    op=s.substr(index,i+1-index);
                    maxlen=i+1-index;
                if(palindrome(op,0,op.length()-1)==true)
                        count++;
                    if(len<maxlen)
                    {
                        countrec(s,i+1,n,op);
                    }
                    op.pop_back();   
                
            }
        }
       
    }
    
     int countSubstrings(string s) {
        int n=s.length();
        string op="";
        countrec(s,0,n,op);
        return count;
    }
    
    */
    
    //dp solution
    int countSubstrings(string s) {
        int n=s.length();
        bool dp[n][n];
        int count=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(i==j)
                    dp[i][j]=true;
                else if(j==i+1)
                {
                     if(s[i]==s[j])
                      dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }    
                else
                {
                   if(s[i]==s[j] && dp[i+1][j-1]==true)
                       dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};