class Solution {
public:
     void dfs(string beginWord,string endWord,vector<string>& str,unordered_map<string,unordered_set<string>>& adj,vector<vector<string>>& allPath)
     {
         str.push_back(beginWord);
         if(beginWord==endWord)
         {
             allPath.push_back(str);
             str.pop_back();
             return;
         }
         for(auto x: adj[beginWord])
            dfs(x,endWord,str,adj,allPath);
       str.pop_back();
       return;
     }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        unordered_map<string,unordered_set<string>>adj;
        unordered_map<string,int>vis;
        vector<vector<string>>allPath;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=0;
        while(!q.empty())
        {
            string str=q.front();
            q.pop();
            string curr=str;
            for(int i=0;i<curr.length();i++)
            {
                 for(char c='a';c<='z';c++)
                {
                     if(curr[i]==c)
                         continue;
                     curr[i]=c;
                    if(dict.count(curr)>0)
                    {
                        if(vis.count(curr)==0)
                        {
                            q.push(curr);
                            vis[curr]=vis[str]+1;
                            adj[str].insert({curr});
                        }
                        else if(vis[curr]==vis[str]+1)
                            adj[str].insert({curr});
                    }
                }
              curr[i]=str[i];  
            }
        }
        // for(auto x: adj)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        vector<string>str;
        dfs(beginWord,endWord,str,adj,allPath);
        return allPath;
    }
};