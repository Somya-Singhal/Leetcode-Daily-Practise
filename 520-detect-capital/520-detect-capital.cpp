class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        bool large=false,small=false;
        if(word[0]>='A' && word[0]<='Z')
            large=true;
        else if(word[0]>='a' && word[0]<='z')
            small=true;
        //case-1
        if(large==true)
        {
            for(int i=1;i<n;i++)
            {
                if(word[i]>='A' && word[i]<='Z')
                    continue;
                else
                {
                    large=false;
                    break;
                }
            }
            //case-3
            if(large==false)
            {
                for(int i=1;i<n;i++)
                {
                   if(word[i]>='a' && word[i]<='z')
                     continue;
                   else
                     return false; 
                }
            }
        }
        //case-2
        else
        {
            for(int i=1;i<n;i++)
            {
                if(word[i]>='a' && word[i]<='z')
                    continue;
                else
                    return false;
            }  
        }
        return true;
    }
};