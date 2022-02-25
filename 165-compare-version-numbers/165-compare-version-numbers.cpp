class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1),s2(version2);
        while(s1.good() || s2.good())
        {
            string str1="",str2="";
            getline(s1,str1,'.');
            getline(s2,str2,'.');
            if(str1=="")
                str1='0';
            if(str2=="")
                str2='0';
            if(atoi(str1.c_str())>atoi(str2.c_str()))
                return 1;
            if(atoi(str1.c_str())<atoi(str2.c_str()))
                return -1;
        }
        return 0;
    }
};