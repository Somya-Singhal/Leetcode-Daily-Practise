class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.length();
        cout<<n;
        int lo=0,hi=n-1;
        int count=0;
        while(lo<hi)
        {
            if(s[lo]!=s[hi])
            {
                int num1=2001,num2=2001;
                for(int i=lo+1;i<hi;i++)
                {
                    if(s[i]==s[hi])
                    {
                       num1=i-lo;
                        break;
                    }
                }
                for(int i=hi-1;i>lo;i--)
                {
                    if(s[i]==s[lo])
                    {
                       num2=hi-i;
                        break;
                    }
                }
                count+=min(num1,num2);
                if(num1<num2)
                    for(int i=num1+lo;i>lo;i--)
                        swap(s[i],s[i-1]);
                else
                    for(int i=hi-num2;i<hi;i++)
                        swap(s[i],s[i+1]);
            }
            lo++;
            hi--;
        }
        return count;
    }
};