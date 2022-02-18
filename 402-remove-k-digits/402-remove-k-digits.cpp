class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k==n)
            return "0";
        stack<int>s;
        int i=0;
        while(i<n)
        {
            
                 while(!s.empty() && k>0 && s.top()>num[i])
                {
                    s.pop();
                    k--;
                }
            
                s.push(num[i]);
                i++;
        }
        while(k>0)
        {
            s.pop();
            k--;
        }
        string temp="";
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }
        reverse(temp.begin(),temp.end());
        if(temp[0]=='0')
        {
            int i=0;
            for(i=1;i<n;i++)
            {
                if(temp[i]!='0')
                    break;
            }
            temp=temp.substr(i);
        }
        return temp==""?"0":temp;
    }
};