class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int no_digit=0;
        int temp=n;
        while(temp>0)
        {
            temp/=2;
            no_digit++;
        }
        int complement=pow(2,no_digit)-1-n;
        return complement;
    }
};