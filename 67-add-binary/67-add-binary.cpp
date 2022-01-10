class Solution {
public:
    string addBinary(string a, string b) {
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
        int n1=a.length(),n2=b.length();
        int i=0,j=0,carry=0;
        string res="";
       while(i<n1 && j<n2)
       {
           int num=(a[i]-'0')+(b[j]-'0')+carry;
           if(num>=2)
           {
               carry=1;
           }
           else
               carry=0;
           num=num%2;
           res+=to_string(num);
           i++,j++;
       }
       while(i<n1)
       {
           int num=(a[i]-'0')+carry;
           if(num>=2)
               carry=1;
           else
               carry=0;
           num=num%2;
           res+=to_string(num);
           i++;
       }
        while(j<n2)
        {
           int num=(b[j]-'0')+carry;
           if(num>=2)
               carry=1;
           else
               carry=0;
           num=num%2;
           res+=to_string(num);
           j++;
        }
        if(carry==1)
            res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};