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
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
       queue<Node*>q;
       int depth=0;
       q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                Node* curr=q.front();
                q.pop();
                for(int j=0;j<curr->children.size();j++)
                {
                    q.push(curr->children[j]);
                }
            }
            depth++;
        }
        return depth;
    }
};