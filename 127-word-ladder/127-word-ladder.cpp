class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>dict(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        q.push({beginWord,1});
        vis.insert(beginWord);
        
        while(!q.empty())
        {
            string t=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(t==endWord)
                return dist;
            for(int i=0;i<t.length();i++)
            {
                 for(char c='a';c<='z';c++)
                {
                    char x=t[i];
                    t[i]=c;
                     if(vis.find(t)==vis.end() && dict.find(t)!=dict.end())
                     {
                         q.push({t,dist+1});
                         vis.insert(t);
                     }
                     t[i]=x;
                }
            }
           
        }
        return 0;
        
        }
};