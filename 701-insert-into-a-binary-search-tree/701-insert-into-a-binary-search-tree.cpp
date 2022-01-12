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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* grand=NULL,*curr=root;
        TreeNode* temp=new TreeNode(val);
        while(curr!=NULL)
        {
            grand=curr;
            if(curr->val>val)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
        if(grand==NULL)
            return temp;
        else{
            if(val<grand->val)
                grand->left=temp;
            else
                grand->right=temp;
        }
        return root;
    }
};