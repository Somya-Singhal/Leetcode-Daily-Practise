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
    //keep track of a count variable and just do inorder traversal
    //here iterative inorder traversal done
    int kthSmallest(TreeNode* root, int k) {
        if(root!=NULL)
        {
        stack<TreeNode*>s;
        TreeNode* curr=root;
        int count=0;
        while(!s.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            count++;
            if(count==k)
            {
                return curr->val;
            }
            curr=curr->right;
        }
        }
         return 0;
    }
};