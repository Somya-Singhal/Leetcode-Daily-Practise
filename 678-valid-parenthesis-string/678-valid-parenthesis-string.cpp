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
    
    //dp->O(n^3)
    //  bool checkString(int idx,int open,string s, vector<vector<bool>>& dp)
    // {
    //     if(idx==s.length() || open<0)
    //         return open==0;
    //      if(dp[idx][open])
    //          return dp[idx][open];
    //     if(s[idx]=='(')
    //         dp[idx][open]=checkString(idx+1,open+1,s,dp);
    //     else if(s[idx]==')')
    //         dp[idx][open]=open!=0 && checkString(idx+1,open-1,s,dp);
    //     else
    //     {
    //         dp[idx][open]=checkString(idx+1,open+1,s,dp) || open!=0 && checkString(idx+1,open-1,s,dp) || checkString(idx+1,open,s,dp);
    //     }
    //      return dp[idx][open];
    // }
    // bool checkValidString(string s) {
    //     int n=s.length();
    //     vector<vector<bool>>dp(n,vector<bool>(n));
    //     return checkString(0,0,s,dp);
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
//     bool checkValidString(string s) {
//          int n=s.length();
//          int leftmin=0,leftmax=0;
//          for(int i=0;i<n;i++)
//          {
//              if(s[i]=='(')
//              {
//                  leftmin++;
//                  leftmax++;
//              }
//              else if(s[i]==')')
//              {
//                 leftmin--;
//                  leftmax--; 
//              }
                 
//              else
//              {
//                  leftmin--;
//                  leftmax++;
//              }
//              if(leftmax<0)
//                  return false;
//              if(leftmin<0)
//                  leftmin=0;
             
//          }
//          return leftmin==0;
//     }
    
    //using stack
     bool checkValidString(string s) {
        int n=s.length();
        stack<int>count,star;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
               count.push(i);
            else if(s[i]==')')
            {
                if(!count.empty())
                    count.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
            else
                star.push(i);
        }
         while(!count.empty())
         {
             if(star.empty() || star.top()<count.top())
                 return false;
             count.pop();
             star.pop();
         }
         return true;
    }
};