class Solution {
public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         unordered_map<string,int>mp;
//         int n=words.size(),len=s.length(),wordSize=words[0].length();
//         vector<int>res;
//         vector<bool>vis(n,false);
//         for(int i=0;i<n;i++)
//             mp[words[i]]++;
//         for(int i=0;i<=len-n*wordSize;i++)
//         {
//             int j=i,count=0;
//             unordered_map<string,int>temp=mp;
//             while(true)
//             {
//                 string str=s.substr(j,wordSize);
//                 if(temp.find(str)!=temp.end())
//                 {
//                     temp[str]--;
//                     if(temp[str]==0)
//                         temp.erase(str);
//                 }
//                 else
//                 {
                   
//                     break;
//                 }
//                 count+=1;
//                 j+=wordSize;  
//             }
//             if(count==n)
//                 res.push_back(i);
//         }
//         return res;
//     }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        int n=words.size(),len=s.length(),wordSize=words[0].length();
        vector<int>res;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
            mp[words[i]]++;
        for(int i=0;i<=len-n*wordSize;i++)
        {
            int j;
            unordered_map<string,int>vis;
            for(j=0;j<n;j++)
            {
                string str=s.substr(i+j*wordSize,wordSize);
                if(mp.find(str)!=mp.end())
                {
                    vis[str]++;
                    if(vis[str]>mp[str])
                      break;
                }
                else
                    break;       
            }
            
            if(j==n)
                res.push_back(i);
        }
        return res;
    }
};