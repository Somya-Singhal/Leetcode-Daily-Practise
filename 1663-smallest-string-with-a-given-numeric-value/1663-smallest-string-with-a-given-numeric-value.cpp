class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=n;i>=1;i--)
        {
            int val;
            if((k-26-i+1)>=0)
            {
                 val=26;
                 ans+='z';
            }
            else{
                val=k-i+1;
                ans+='a'+val-1;
            }
            k-=val;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};