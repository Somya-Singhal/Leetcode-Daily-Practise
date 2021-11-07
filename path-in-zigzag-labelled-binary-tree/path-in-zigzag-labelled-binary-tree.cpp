class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int temp=label;
        vector<int>res;
        int store,myend;
        res.push_back(label);
        while(temp>1)
        {
            int level=log2(temp);
            int start=pow(2,level);
            int find=pow(2,level+1)-1;
            if(temp%2==0)
            {
                store=find-temp;
                myend=start+store;
            }
            else
            {
                
                store=temp-start;
                myend=find-store;
            }
            myend=myend/2;
            temp=myend;
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};