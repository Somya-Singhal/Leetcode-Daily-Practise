class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        long long int up=1;
        res.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            up*=(rowIndex-i+1);
            up/=i;
            res.push_back(up);
        }
        return res;
    }
};