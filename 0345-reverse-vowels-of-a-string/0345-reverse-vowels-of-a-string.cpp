class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        vector<char>pos;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                pos.push_back(s[i]);
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                 s[i]=pos[j++];
        }
        return s;
    }
};