class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n=strs.size();
        int len=strs[0].length();
        
        for(int i=1;i<n;i++)
        {
            int curr=strs[i].length();
            len=min(len,curr);
        }
        // cout<<len<<" ";
        for(int i=0;i<len;i++)
        {
            char ch=strs[0][i];
            int j;
            for(j=1;j<n;j++)
            {
                if(strs[j][i]!=ch)
                    return res;
            }
            if(j==n)
                res+=ch;
        }
        return res;
    }
};