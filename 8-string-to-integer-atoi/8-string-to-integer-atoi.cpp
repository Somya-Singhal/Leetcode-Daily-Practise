class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        bool neg=false,read=false,seen=false;
        long int num=0;
        int left=-pow(2,31),right=pow(2,31)-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-' && seen==false && read==false)
            {
                seen=true;
                neg=true;
                continue;
            }
            else if(s[i]=='+' && seen==false && read==false)
            {
                seen=true;
                continue;
            }
            else if(s[i]==' ' && read==false && seen==false)
                continue;
            else if(read==false && !(s[i]>='0' && s[i]<='9'))
                    return 0;
            else if(read==true && !(s[i]>='0' && s[i]<='9'))
                    break;
            else if(seen==true && (s[i]=='-' || s[i]=='+'))
                return 0;
            else if(s[i]>='0' && s[i]<='9')
            {
               read=true;
               num=num*10+(s[i]-'0'); 
                if(-num<=left && neg==true)
                return left;
                else if(num>=right && neg==false)
                return right;
            }
        }
        
        return (neg==true)?-num:num;
    }
};