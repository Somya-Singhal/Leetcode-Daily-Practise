class Solution {
public:
    //using dfs
    // void dfs(vector<int>& s1,set<vector<int>>& vis,vector<vector<int>>& stones)
    // {
    //     vis.insert({s1});
    //     for(auto s2:stones)
    //     {
    //         if(vis.find(s2)==vis.end())
    //         {
    //             if(s1[0]==s2[0] || s1[1]==s2[1])
    //               dfs(s2,vis,stones);
    //         }
    //     }
    // }
    // int removeStones(vector<vector<int>>& stones) {
    //     set<vector<int>>vis;
    //     int n=stones.size(),countgrps=0;
    //     for(auto s1:stones)
    //     {
    //         if(vis.find(s1)==vis.end())
    //         {
    //             dfs(s1,vis,stones);
    //             countgrps++;
    //         }
    //     }
    //     return (n-countgrps);
    // }
    
    //using union find
    // int count=0;
    // string find(string s1,unordered_map<string,string>& parent)
    // {
    //     if(parent[s1]!=s1)
    //         return parent[s1]=find(parent[s1],parent);
    //     else
    //         return parent[s1];
    // }
    // void myunion(string s1,string s2,unordered_map<string,int>& rank,unordered_map<string,string>& parent)
    // {
    //     string s12=find(s1,parent);
    //     string s21=find(s2,parent);
    //     if(parent[s12]==s21)
    //         return;
    //     if(rank[s12]<rank[s21])
    //         parent[s12]=s21;
    //     else if(rank[s12]>rank[s21])
    //         parent[s21]=s12;
    //     else
    //     {
    //        parent[s21]=s12;
    //        rank[s12]++; 
    //     }
    //     count--;
    // }
    // int removeStones(vector<vector<int>>& stones) {
    //     unordered_map<string,string>parent;
    //     count=stones.size();
    //     unordered_map<string,int>rank;
    //     for(auto x:stones)
    //     {
    //        string s1=to_string(x[0])+" "+to_string(x[1]);
    //        parent.insert({s1,s1});
    //        rank[s1]=0;
    //     }
    //     for(auto s1:stones)
    //     {
    //         string ss1=to_string(s1[0])+" "+to_string(s1[1]);
    //         for(auto s2:stones)
    //         {
    //             string ss2=to_string(s2[0])+" "+to_string(s2[1]);
    //             if(s1[0]==s2[0] || s1[1]==s2[1])
    //                 myunion(ss1,ss2,rank,parent);
    //         }
    //     }
    //     return stones.size()-count;
    // }
    
    //time->O(n)
    unordered_map<int,int>mp;
    int islands=0;
    int find(int x)
    {
        if(mp.find(x)==mp.end())
        {
            mp[x]=x;
            islands++;
        }
        if(mp[x]!=x)
            return find(mp[x]);
        return mp[x];
    }
     void myunion(int x,int y)
     {
         int x1=find(x),y1=find(y);
         if(x1!=y1)
         {
             mp[x1]=y1;
             islands--;
         }
     }
     int removeStones(vector<vector<int>>& stones) {
         for(auto x:stones)
         {
             myunion(x[0],~x[1]);
         }
         return stones.size()-islands;
     }
};