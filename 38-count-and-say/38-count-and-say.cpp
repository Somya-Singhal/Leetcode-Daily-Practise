class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string res=countAndSay(n-1);
         // cout<<res<<" "<<endl;
        string ans="";
        int ch=0,count=1;
        for(int i=1;i<res.length();i++)
        {
            if(res[i]!=res[ch])
            {
                ans+=to_string(count)+res[ch];
                count=1;
                ch=i;
            }
            else
                count++;
        }
        ans+=to_string(count)+res[ch];
       
        return ans;
    }
};