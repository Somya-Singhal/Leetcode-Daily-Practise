class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>ch(26,0);
        int n1=s.length(),n2=t.length();
        char res;
        for(int i=0;i<n1;i++)
            ch[s[i]-'a']++;
        
        for(int i=0;i<n2;i++)
            ch[t[i]-'a']--;
        for(int i=0;i<26;i++)
        {
            if(ch[i]==-1)
                res=i+'a';
        }
        return res;
    }
};