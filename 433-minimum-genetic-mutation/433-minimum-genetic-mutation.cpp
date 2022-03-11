class Solution {
public:
    // int minMutation(string start, string end, vector<string>& bank) {
    //     if(start.length()!=end.length())
    //         return -1;
    //     unordered_set<string>word;
    //     unordered_set<string>vis;
    //     vector<char>list{'A','C','G','T'};
    //     for(auto x: bank)
    //     {
    //         word.insert({x});
    //     }
    //     int level=0;
    //     queue<string>q;
    //     vis.insert({start});
    //     q.push(start);
    //     while(!q.empty())
    //     {
    //         int len=q.size();
    //         for(int l=0;l<len;l++) 
    //         {
    //             string curr=q.front();
    //             q.pop();
    //             if(curr==end)
    //                 return level;
    //             string temp=curr;
    //             for(int i=0;i<temp.length();i++)
    //             {
    //                 for(int j=0;j<list.size();j++)
    //                 {
    //                     temp[i]=list[j];
    //                     if(vis.find(temp)==vis.end() && word.find(temp)!=word.end())
    //                     {
    //                         vis.insert({temp});
    //                         q.push(temp);
    //                     }
    //                     temp[i]=curr[i];
    //                 }
    //             }
    //          }
    //         level++;
    //     }
    //     return -1;
    // }
    
    //some memory saved
     int minMutation(string start, string end, vector<string>& bank) {
        if(start.length()!=end.length())
            return -1;
        unordered_set<string>word;
        vector<char>list{'A','C','G','T'};
        for(auto x: bank)
        {
            word.insert({x});
        }
        int level=0;
        queue<string>q;
        q.push(start);
        while(!q.empty())
        {
            int len=q.size();
            for(int l=0;l<len;l++) 
            {
                string curr=q.front();
                q.pop();
                if(curr==end)
                    return level;
                string temp=curr;
                for(int i=0;i<temp.length();i++)
                {
                    for(int j=0;j<list.size();j++)
                    {
                        temp[i]=list[j];
                        if(word.find(temp)!=word.end())
                        {
                            word.erase(temp);
                            q.push(temp);
                        }
                        temp[i]=curr[i];
                    }
                }
             }
            level++;
        }
        return -1;
    }
};