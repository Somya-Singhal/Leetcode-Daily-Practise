/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m=height(root);
        int n=pow(2,m)-1;
        vector<vector<string>>res(m,vector<string>(n));
        res[0][(n-1)/2]=to_string(root->val);
        queue<pair<pair<int,int>,TreeNode*>>q;
        q.push(make_pair(make_pair(0,(n-1)/2),root));
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                pair<pair<int,int>,TreeNode*>p1=q.front();
                int row=p1.first.first;
                int col=p1.first.second;
                TreeNode* curr=p1.second;
                q.pop();
                if(curr->left)
                {
                   int newrow=row+1;
                   int newcol=col-pow(2,m-row-2);
                    res[newrow][newcol]=to_string(curr->left->val);
                   q.push(make_pair(make_pair(newrow,newcol),curr->left));
                   
                }
                if(curr->right)
                {
                   int newrow=row+1;
                   int newcol=col+pow(2,m-row-2);
                    res[newrow][newcol]=to_string(curr->right->val);
                   q.push(make_pair(make_pair(newrow,newcol),curr->right));
                }
            }
        }
        return res;
    }
};