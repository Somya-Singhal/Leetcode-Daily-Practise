class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int n1=t.length(),n2=s.length();
        if(n1<n2)
            return false;
        for(int j=0;j<n1;j++)
        {
            if(i==n2)
                break;
            if(s[i]==t[j])
                i++;
        }
        return (i==n2);
    }
};