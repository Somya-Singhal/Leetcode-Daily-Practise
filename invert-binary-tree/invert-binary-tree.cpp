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
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==NULL)
//             return root;
//         TreeNode* temp=root->left;
//         root->left=invertTree(root->right);
//         root->right=invertTree(temp);
//         return root;
//     }
    
    // same solution can be written using stack also
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* tmp=curr->left;
            curr->left=curr->right;
            curr->right=tmp;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return root;
    }
};
