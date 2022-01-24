/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //time:O(n), space:O(width);
    //BFS
    // int maxDepth(Node* root) {
    //     if(root==NULL)
    //         return 0;
    //    queue<Node*>q;
    //    int depth=0;
    //    q.push(root);
    //     while(!q.empty())
    //     {
    //         int len=q.size();
    //         for(int i=0;i<len;i++)
    //         {
    //             Node* curr=q.front();
    //             q.pop();
    //             for(int j=0;j<curr->children.size();j++)
    //             {
    //                 q.push(curr->children[j]);
    //             }
    //         }
    //         depth++;
    //     }
    //     return depth;
    // }
    
    //DFS
    int maxdepth=0;
    void dfs(Node* root,int depth)//passed depth by reference(C++)
    {
        if(root==NULL)
            return;
        if(maxdepth<depth)
        {
            maxdepth=depth;
        }
        for(int i=0;i<root->children.size();i++)
        {
            dfs(root->children[i],depth+1);
        }
        return;
    }
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
       dfs(root,1);
        return maxdepth;
    }
};