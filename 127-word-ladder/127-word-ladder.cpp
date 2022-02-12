class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        unordered_map<string,unordered_set<string>>adj;
        unordered_map<string,int>vis;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=0;
        while(!q.empty())
        {
            string str=q.front();
            q.pop();
            string temp=str;
            for(int i=0;i<temp.length();i++)
            {
                for(char c='a';c<='z';c++)
                {
                    if(temp[i]==c)
                        continue;
                    temp[i]=c;
                    if(dict.find(temp)!=dict.end())
                    {
                        if(vis.find(temp)==vis.end())
                        {
                            vis[temp]=vis[str]+1;
                            adj[str].insert(temp);
                            q.push(temp);
                        }
                        else if(vis[temp]==vis[str]+1)
                        {
                            adj[str].insert(temp);
                        }
                    }
                    temp[i]=str[i];
                }
            }
        }
        return vis.count(endWord)>0?vis[endWord]+1:0;
    }
};