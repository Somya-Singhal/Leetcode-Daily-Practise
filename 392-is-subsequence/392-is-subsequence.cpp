class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int n=t.length();
        if(n<s.length())
            return false;
        for(int j=0;j<n;j++)
        {
            if(i==s.length())
                break;
            if(t[j]==s[i])
                i++;
        }
        return (i==s.length());
    }
};