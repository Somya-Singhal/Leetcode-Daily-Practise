class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length(),n2=t.length();
        if(n2>n1 || t=="" || s=="")
            return "";
        unordered_map<char,int>mp;
        string res="";
        int ans=INT_MAX,minleft=0;
        int left=0,len=0;
        for(int i=0;i<n2;i++)
            mp[t[i]]++;
        for(int i=0;i<n1;i++)
        {
           if(mp.find(s[i])!=mp.end())
           {
               
                   mp[s[i]]--;
                   if(mp[s[i]]>=0)
                       len++;
           while(len==n2)
           {
               if(ans>i-left+1)
               {
                   ans=i-left+1;
                   minleft=left;
               }
               if(mp.find(s[left])!=mp.end())
               {
                   mp[s[left]]++;
                   if(mp[s[left]]>0)
                        len--;
               }
               left++;
           }
           }
          
        }
        
        return ans==INT_MAX?"":s.substr(minleft,ans);
    }
};