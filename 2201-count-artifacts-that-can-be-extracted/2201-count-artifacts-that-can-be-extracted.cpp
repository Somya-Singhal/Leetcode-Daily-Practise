class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<string>s;
        int d=dig.size(),a=artifacts.size();
        for(int i=0;i<d;i++)
        {
            s.insert({to_string(dig[i][0]) + " " + to_string(dig[i][1])});
        }
        int count=0;
        for(int i=0;i<a;i++)
        {
            bool flag=true;
               for(int j=artifacts[i][0];j<=artifacts[i][2];j++)
               {
                   for(int k=artifacts[i][1];k<=artifacts[i][3];k++)
                   {
                       if(s.find(to_string(j) + " " + to_string(k))==s.end())
                       {
                           flag=false;
                           break;
                       }
                   }
                   if(flag==false)
                       break;
               }
                if(flag)
                    count++;
        }
        return count;
    }
};