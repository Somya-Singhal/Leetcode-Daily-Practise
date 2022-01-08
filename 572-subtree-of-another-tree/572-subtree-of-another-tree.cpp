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
    // bool inorder(TreeNode* root, TreeNode* subRoot)
    // {
    //     if(root==NULL && subRoot==NULL)
    //         return true;
    //     if(root==NULL || subRoot==NULL)
    //         return false;
    //     if(inorder(root->left,subRoot->left)==false)
    //         return false;
    //     if(root->val!=subRoot->val)
    //         return false;
    //     return inorder(root->right,subRoot->right);
    // }
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL))
    //         return false;
    //     if(root->val==subRoot->val)
    //     {
    //         if(inorder(root,subRoot)==true)
    //             return true;
    //     }
    //     if(isSubtree(root->left,subRoot)==true)
    //         return true;
    //     return isSubtree(root->right,subRoot);
    // }
    
    //shorter solution
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL || subRoot==NULL)
            return false;
        if(root->val!=subRoot->val)
            return false;
        return isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(isSame(root,subRoot))
        return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};