class Solution {
public:
    bool isValidSerialization(string preorder) {
      stringstream ss(preorder);
      int degree=1;
        while(ss.good())
        {
            string substr;
            getline(ss,substr,',');
             if(--degree<0)
              return false;
             if(substr!="#")
              degree+=2;
        }
        return degree==0;
    }
};