class Solution {
public:
    bool palin(string s,int st,int e)
    {
        while(st<=e)
        {
            if(s[st]!=s[e])
                return false;
            st++;
            e--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int l=0,h=n-1;
        while(l<=h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else{
                return palin(s,l+1,h) || palin(s,l,h-1);
            }
        }
        return true;
    }
};