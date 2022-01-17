class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.length();
        stringstream ss(s);
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        int i=0;
        while(ss.good())
        {
            string str;
            getline(ss,str,' ');
            if(mp1.find(pattern[i])!=mp1.end())
            {
                if(mp1[pattern[i]]!=str)
                    return false;
            }
            else if(mp2.find(str)!=mp2.end())
            {
                if(mp2[str]!=pattern[i])
                    return false;
            }
            else
            {
                if(mp1.find(pattern[i])==mp1.end())
                mp1.insert({pattern[i],str});
                if(mp2.find(str)==mp2.end())
                    mp2.insert({str,pattern[i]});
            }
            i++;
        }
        return (i==n);
        
    }
};