/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool constructpath(TreeNode* root,TreeNode* node,vector<TreeNode*>& path)
    {
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root==node)
            return true;
        if(constructpath(root->left,node,path) || constructpath(root->right,node,path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        TreeNode* ans=NULL;
        if(constructpath(root,p,path1)==false || constructpath(root,q,path2)==false)
            return NULL;
        for(int i=0;i<path1.size() && i<path2.size() ;i++)
        {
            if(path1[i]==path2[i])
                ans=path1[i];
        }
        return ans;
    }
};