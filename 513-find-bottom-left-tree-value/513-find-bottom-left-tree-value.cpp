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
    void findBottom(TreeNode* root,int &maxdepth,int depth,int &ans)
    {
        if(root==NULL)
            return;
        if(depth>maxdepth)
        {
           ans=root->val;
           maxdepth=depth;
        }
        findBottom(root->left,maxdepth,depth+1,ans);
        findBottom(root->right,maxdepth,depth+1,ans);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        int maxdepth=-1;
        findBottom(root,maxdepth,0,ans);
        return ans;
    }
};