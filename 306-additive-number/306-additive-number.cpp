class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=(n-i)/2;j++)
            {
                if(check(num.substr(0,i),num.substr(i,j),num.substr(i+j)))
                   return true;
            }
        }
        return false;
    }
    bool check(string num1,string num2,string num3)
    {
        if((num1[0]=='0' && num1.size()>1) || (num2[0]=='0' && num2.size()>1))
            return false;
        string sum=add(num1,num2);
        if(num3==sum)
            return true;
        if(num3.size()<=sum.size() || sum.compare(num3.substr(0,sum.size()))!=0)
            return false;
        else return check(num2,sum,num3.substr(sum.size()));
    }
    string add(string num1,string num2)
    {
        string res;
        int carry=0;
        int n1=num1.size()-1,n2=num2.size()-1;
        while(n1>=0 || n2>=0)
        {
           int sum=carry+(n1>=0?num1[n1--]-'0':0)+(n2>=0?num2[n2--]-'0':0);
            res+=sum%10+'0';
            carry=sum/10;
        }
        if(carry)
            res+=carry+'0';
        reverse(res.begin(),res.end());
        return res;
    }
};