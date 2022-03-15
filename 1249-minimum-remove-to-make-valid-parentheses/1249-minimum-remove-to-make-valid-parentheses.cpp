class Solution {
public:
        
    // string minRemoveToMakeValid(string s) {
    //     int n=s.length();
    //     string str1=s,str2=s;
    //     stack<int>st;
    //     for(int i=0;i<n;i++)
    //     {
    //        if(s[i]=='(')
    //            st.push(i);
    //         if(s[i]==')')
    //         {
    //             if(!st.empty())
    //                 st.pop();
    //             else
    //                 s[i]='*';
    //         }
    //     }
    //     while(!st.empty())
    //     {
    //         s[st.top()]='*';
    //         st.pop();
    //     }
    //     s.erase(remove(s.begin(),s.end(),'*'),s.end());
    //     return s;
    // }
    
     string minRemoveToMakeValid(string s) {
         int n=s.length();
         int count=0;
         for(int i=0;i<n;i++)
         {
             if(s[i]=='(')
                 count++;
             else if(s[i]==')')
             {
                 if(count==0)
                     s[i]='*';
                 else
                     count--;
             }
         }
         count=0;
         for(int i=n-1;i>=0;i--)
         {
             if(s[i]==')')
                 count++;
             else if(s[i]=='(')
             {
                 if(count==0)
                     s[i]='*';
                 else
                     count--;
             }
         }
         string ans="";
         for(int i=0;i<n;i++)
         {
             if(s[i]!='*')
                 ans+=s[i];
         }
         return ans;
     }
};