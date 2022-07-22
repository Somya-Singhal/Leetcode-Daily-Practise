class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0,l=0;
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count==0)
            {
                ans+=s.substr(l+1,i-l-1);
                l=i+1;
            }
              
        }
        return ans;
    }
};