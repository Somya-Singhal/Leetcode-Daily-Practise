class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(),m=needle.length();
        // int d=256,h=0,t=0,p=0,q=23;
        // for(int i=0;i<m-1;i++)
        //     h=(h*d)%q;
        // for(int i=0;i<m;i++)
        // {
        //     t=(t*d+haystack[i])%q;
        //     p=(p*d+needle[i])%q;
        // }
        for(int i=0;i<=n-m;i++)
        {
            // if(t==p)
            // {
            //     int j;
            //     for(j=0;j<m;j++)
            //     {
            //         if(haystack[j+i]!=needle[j])
            //         break;  
            //     }
            //     if(j==m)
            //         return i;
            // }
            // if(i<n-m)
            // {
            //     t=(d*(t-haystack[i]*h)+haystack[i+m])%q;
            //     if(t<q)
            //        t+=q;
            // }
            int j;
             for(j=0;j<m;j++)
                {
                    if(haystack[j+i]!=needle[j])
                    break;  
                }
                if(j==m)
                    return i;
        }
        return -1;
    }
};