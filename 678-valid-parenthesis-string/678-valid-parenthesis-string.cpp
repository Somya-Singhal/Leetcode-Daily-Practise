class Solution {
public:
    //recursive
    // bool checkString(int idx,int open,int close,string s)
    // {
    //     if(idx==s.length())
    //         return open==close;
    //     if(s[idx]=='(')
    //         return checkString(idx+1,open+1,close,s);
    //     if(s[idx]==')')
    //         return checkString(idx+1,open,close+1,s);
    //     return checkString(idx+1,open+1,close,s) || checkString(idx+1,open,close+1,s) || checkString(idx+1,open,close,s);
    // }
    // bool checkValidString(string s) {
    //     return checkString(0,0,0,s);
    // }
    
    //greedy->O(n) (but not intuitive :') 
    //1st approach
    //  bool checkValidString(string s) {
    //      int n=s.length();
    //      int lo=0,hi=0;
    //      for(int i=0;i<n;i++)
    //      {
    //          lo+=s[i]=='('?1:-1;
    //          hi+=s[i]!=')'?1:-1;
    //          if(hi<0)
    //              break;
    //          lo=max(lo,0);
    //      }
    //      return lo==0;
    // }
    
    //2nd approach
    bool checkValidString(string s) {
         int n=s.length();
         int leftmin=0,leftmax=0;
         for(int i=0;i<n;i++)
         {
             if(s[i]=='(')
             {
                 leftmin++;
                 leftmax++;
             }
             else if(s[i]==')')
             {
                leftmin--;
                 leftmax--; 
             }
                 
             else
             {
                 leftmin--;
                 leftmax++;
             }
             if(leftmax<0)
                 return false;
             if(leftmin<0)
                 leftmin=0;
             
         }
         return leftmin==0;
    }
};