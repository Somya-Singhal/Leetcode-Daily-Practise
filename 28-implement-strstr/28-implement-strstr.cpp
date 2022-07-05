class Solution {
public:
    void buildLPS(string p,int *lps,int m)
    {
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m)
        {
            if(p[i]==p[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                    len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n=haystack.length(),m=needle.length();
        // int d=256,h=1,t=0,p=0,q=91;
        // for(int i=0;i<m-1;i++)
        //     h=(h*d)%q;
        // for(int i=0;i<m;i++)
        // {
        //     t=(t*d+haystack[i])%q;
        //     p=(p*d+needle[i])%q;
        // }
        // for(int i=0;i<=n-m;i++)
        // {
        //     if(t==p)
        //     {
        //         int j;
        //         for(j=0;j<m;j++)
        //         {
        //             if(haystack[j+i]!=needle[j])
        //             break;  
        //         }
        //         if(j==m)
        //             return i;
        //     }
        //     if(i<n-m)
        //     {
        //         t=(d*(t-haystack[i]*h)+haystack[i+m])%q;
        //         if(t<q)
        //            t+=q;
        //     }
        // }
        // return -1;
        
        int lps[m];
        buildLPS(needle,lps,m);
        int i=0,j=0;
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++,j++;
            }
            if(j==m)
            {
                return i-m;
            }
            else if(i<n && haystack[i]!=needle[j])
            {
                if(j!=0)
                    j=lps[j-1];
                else
                   i++; 
            }
        }
        return -1;
    }
};