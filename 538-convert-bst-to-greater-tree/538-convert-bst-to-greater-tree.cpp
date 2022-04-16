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
//     int sum=0;
//     TreeNode* convertBST(TreeNode* root) {
        
//         if(root!=NULL){
//             convertBST(root->right);
//             sum+=root->val;
//             root->val=sum;
//             convertBST(root->left); 
//         }
//         return root;
//     }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return root;
        stack<TreeNode*>s;
        int sum=0;
        TreeNode* curr=root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->right;
            }
            curr=s.top();
            s.pop();
            curr->val+=sum;
            sum=curr->val;
            curr=curr->left;
        }
        return root;
    }
};