class Solution {
public:
    // bool isValidSerialization(string preorder) {
    //   stringstream ss(preorder);
    //   int degree=1;
    //     while(ss.good())
    //     {
    //         string substr;
    //         getline(ss,substr,',');
    //          if(--degree<0)
    //           return false;
    //          if(substr!="#")
    //           degree+=2;
    //     }
    //     return degree==0;
    // }
    
    //stack used
    bool isValidSerialization(string preorder) {
        stack<string>s;
        stringstream ss(preorder);
        while(ss.good())
        {
            string str;
            getline(ss,str,',');
            while(str=="#" && !s.empty() && s.top()=="#")
            {
                s.pop();
                if(s.empty())
                    return false;
                s.pop();
            }
            s.push(str);
        }
        return s.size()==1 && s.top()=="#";
    }
};
