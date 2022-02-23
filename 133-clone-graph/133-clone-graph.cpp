/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void clonerec(Node* root,Node* clone,vector<Node*>& visited)
    {
        visited[root->val]=root;
        for(auto x:clone->neighbors)
        {
            if(visited[x->val]==NULL)
            {
                Node* newnode=new Node(x->val);
                (root->neighbors).push_back(newnode);
                clonerec(newnode,x,visited);
            }
            else
            {
               (root->neighbors).push_back(visited[x->val]); 
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
       vector<Node*>visited(1000,NULL);
       Node* temp=new Node(node->val);
        visited[temp->val]=temp;
        for(auto x:node->neighbors)
        {
            if(visited[x->val]==NULL)
            {
                Node* newnode=new Node(x->val);
                (temp->neighbors).push_back(newnode);
                clonerec(newnode,x,visited);
            }
            else
            {
               (temp->neighbors).push_back(visited[x->val]); 
            }
        }
        return temp;
    }

};