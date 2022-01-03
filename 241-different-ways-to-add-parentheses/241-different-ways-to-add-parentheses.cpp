class Solution {
public:
    //recursion
    // vector<int> diffWaysToCompute(string expression) {
    //     int n=expression.length();
    //     vector<int>res;
    //     for(int i=0;i<n;i++)
    //     {
    //         int curr=expression[i];
    //         if(curr=='+' || curr=='-' || curr=='*')
    //         {
    //             vector<int>l=diffWaysToCompute(expression.substr(0,i));
    //             vector<int>r=diffWaysToCompute(expression.substr(i+1));
    //             for(auto x:l)
    //             {
    //                 for(auto y:r)
    //                 {
    //                     if(curr=='+')
    //                         res.push_back(x+y);
    //                     else if(curr=='-')
    //                         res.push_back(x-y);
    //                     else if(curr=='*')
    //                         res.push_back(x*y);
    //                 }
    //             }
    //         }
    //     }
    //     if(res.empty())
    //     {
    //         res.push_back(atoi(expression.c_str()));
    //     }
    //     return res;
    // }
    
    //memoization
    vector<int> diffWaysrec(string expression,unordered_map<string,vector<int>>& mp)
    {
        int n=expression.length();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int curr=expression[i];
            if(curr=='+' || curr=='-' || curr=='*')
            {
                string str1=expression.substr(0,i);
                vector<int>l,r;
                if(mp.find(str1)!=mp.end())
                    l=mp[str1];
                else
                   l=diffWaysrec(str1,mp);
                string str2=expression.substr(i+1);
                if(mp.find(str2)!=mp.end())
                    r=mp[str2];
                else
                    r=diffWaysrec(str2,mp);
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
        return mp[expression]=res; 
    }
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>>mp;
        return diffWaysrec(expression,mp);
    }
};