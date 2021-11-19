class Solution {
public:
    string decodeString(string s) {
        stack<string>str;
        stack<int>num;
        str.push("");
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                int c=stoi(&s[i]);
                while(i<s.length() && isdigit(s[i]))
                    i++;
                num.push(c);
                str.push("");
            }
            else if(s[i]==']')
            {
                int n=num.top();
                num.pop();
                string res=str.top();
                str.pop();
                while(n-->0)
                {
                   str.top().append(res);
                }
            }
            else
                str.top().push_back(s[i]);
        }
        return str.top();
    }
};