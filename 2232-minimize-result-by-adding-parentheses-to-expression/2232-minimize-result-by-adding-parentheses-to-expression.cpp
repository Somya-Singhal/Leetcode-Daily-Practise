class Solution {
public:
   
    string minimizeResult(string expression) {
        int n=expression.length();
        string num1="",num2="";
        int idx=expression.find("+");
        num1=expression.substr(0,idx);
        num2=expression.substr(idx+1,n-idx-1);
        int n1=num1.length(),n2=num2.length();
        int left=0,mid=0,right=0;
        int res=INT_MAX;
        string ans="";
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i==0)
                    left=1;
                else
                    left=stoi(num1.substr(0,i));
                mid=stoi(num1.substr(i,n1-i))+stoi(num2.substr(0,j+1));
                if(j==n2-1)
                    right=1;
                else
                    right=stoi(num2.substr(j+1,n2-j));
                int val=left*mid*right;
                if(val<res){
                    res=val;
                    ans=num1.substr(0,i)+"("+num1.substr(i,n1-i)+"+"+num2.substr(0,j+1)+")"+num2.substr(j+1,n2-j);
                }
            }
        }
        return ans;
    }
};