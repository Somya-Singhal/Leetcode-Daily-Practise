class Solution {
public:
    struct TrieNode{
        struct TrieNode *children[26];
        string word;
    };
    
    struct TrieNode *newnode()
    {
        struct TrieNode *ptr=new TrieNode;
        for(int i=0;i<26;i++)
            ptr->children[i]=NULL;
        ptr->word="";
        return ptr;
    }
    void addnode(struct TrieNode *root,string str)
    {
        struct TrieNode *curr=root;
        for(int i=0;i<str.length();i++)
        {
            char c=str[i];
            if(curr->children[c-'a']==NULL)
                curr->children[c-'a']=newnode();
            curr=curr->children[c-'a'];
        }
        curr->word=str;
    }
    void dfs(int i,int j,struct TrieNode *root,vector<vector<char>>& board,vector<string>& res)
    {
        char c=board[i][j];
        if(c=='#' || root->children[c-'a']==NULL)
            return;
        root=root->children[c-'a'];
        if(root->word!="")
        {
            res.push_back(root->word);
            root->word="";
        }
        board[i][j]='#';
        if(i>0)
            dfs(i-1,j,root,board,res);
        if(j>0)
            dfs(i,j-1,root,board,res);
        if(i<board.size()-1)
            dfs(i+1,j,root,board,res);
        if(j<board[0].size()-1)
            dfs(i,j+1,root,board,res);
        board[i][j]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=words.size();
        int r=board.size(),c=board[0].size();
        vector<string>res;
        struct TrieNode *root=newnode();
        for(int i=0;i<n;i++)
            addnode(root,words[i]);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dfs(i,j,root,board,res);
            }
        }
        return res;
    }
};