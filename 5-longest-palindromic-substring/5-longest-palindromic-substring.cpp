class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(s=="" || s.length()<=1)
            return s;
        int start=0,maxlen=1,lo,hi;
        for(int i=0;i<n;i++)
        {
            lo=i-1,hi=i+1;
            while(lo>=0 && s[lo]==s[i])
                lo--;
            while(hi<n && s[hi]==s[i])
                hi++;
            while(lo>=0 && hi<n && s[lo]==s[hi])
            {
                lo--;
                hi++;
            }
            int len=hi-lo-1;
            if(maxlen<len)
            {
                start=lo+1,
                maxlen=len;
            }
        }
        return s.substr(start,maxlen);
        
      
    }
};