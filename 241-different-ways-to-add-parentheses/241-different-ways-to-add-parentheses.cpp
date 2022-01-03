class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int curr=expression[i];
            if(curr=='+' || curr=='-' || curr=='*')
            {
                vector<int>l=diffWaysToCompute(expression.substr(0,i));
                vector<int>r=diffWaysToCompute(expression.substr(i+1));
                for(auto x:l)
                {
                    for(auto y:r)
                    {
                        if(curr=='+')
                            res.push_back(x+y);
                        else if(curr=='-')
                            res.push_back(x-y);
                        else if(curr=='*')
                            res.push_back(x*y);
                    }
                }
            }
        }
        if(res.empty())
        {
            res.push_back(atoi(expression.c_str()));
        }
        return res;
    }
};