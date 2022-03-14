class Solution {
public:
    string simplifyPath(string path) {
        string canonicalPath="";
        path+='/';
        int n=path.length();
        string curr="";
        vector<string>s;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                if(curr=="")
                    continue;
                if(curr=="..")
                {
                    if(s.size()!=0)
                        s.pop_back();
                }
                else if(curr!=".")
                    s.push_back(curr);
                curr="";
            }
            else
                curr+=path[i];
        }
        // if(curr==".." && s.size()>0)
        //     s.pop_back();
        // else if(curr!=".")
        //     s.push_back(curr);
        for(auto x: s)
        {
            canonicalPath+='/'+x;
        }
        // reverse(canonicalPath.begin(),canonicalPath.end());
        return canonicalPath.size()==0?"/":canonicalPath;
    }
};