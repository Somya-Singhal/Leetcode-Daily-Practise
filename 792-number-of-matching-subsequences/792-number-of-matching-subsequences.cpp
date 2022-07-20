class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n1=s.length(),n2=words.size(),count=0;
        unordered_map<string,int>m;
        for(int i=0;i<n2;i++)
        {
            int j=0,len=words[i].length();
            if(len>n1)
                continue;
            if(m.find(words[i])!=m.end())
            {
                count+=m[words[i]];
                continue;
            }
            for(int k=0;k<n1;k++)
            {
                if(j==len)
                    break;
                if(words[i][j]==s[k])
                    j++;
            }
            if(j==len)
            {
                count++;
                m[words[i]]=1;
            }
            else
                m[words[i]]=0;
        }
        return count;
    }
};