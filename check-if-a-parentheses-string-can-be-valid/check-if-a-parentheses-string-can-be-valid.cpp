class Solution {
public:
    //recursive
    // bool validrec(int idx,int open,int close,string s,string locked)
    // {
    //     if(idx>s.length())
    //         return false;
    //     if(idx==s.length() && open==close)
    //         return true;    
    //     if(locked[idx]=='0')
    //     return validrec(idx+1,open,close+1,s,locked) || validrec(idx+1,open+1,close,s,locked);
    //     return validrec(idx+1,open,close,s,locked);
    // }
    // bool canBeValid(string s, string locked) {
    //     if(s[0]==')' && locked[0]=='1')
    //         return false;
    //     return validrec(0,0,0,s,locked);
    // }
    
    //greedy
     bool canBeValid(string s, string locked) {
         if(s.length()%2==1)
             return false;
         int unlocked=0,lopen=0,lclose=0;
        for(int i=0;i<s.length();i++)
        {
            if(locked[i]=='1')
            {
                 if(s[i]=='(')
                   lopen++;
                 else
                   lclose++;
            }
            else
            unlocked++;
            int unpair=lclose-lopen;
            if(unpair>unlocked)
                return false;
        }
         unlocked=0,lclose=0,lopen=0;
         for(int i=s.length()-1;i>=0;i--)
         {
             if(locked[i]=='1')
            {
                 if(s[i]=='(')
                   lopen++;
                 else
                   lclose++;
            }
            else
            unlocked++;
            int unpair=lopen-lclose;
            if(unpair>unlocked)
                return false;
         }
         return true;
    }
};