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
    //     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         TreeNode* curr=root;
//         if(p->val>q->val)
//             {
//                TreeNode* temp=p;
//                p=q;
//                q=temp;
//             }
//         while(curr!=NULL)
//         {
//             if(curr->val>p->val && curr->val<q->val)
//               return curr;
//             if(curr->val==p->val || curr->val==q->val)
//                 return curr;
//             if(curr->val<p->val)
//                 curr=curr->right;
//             else
//                 curr=curr->left;
//         }
//         return NULL;
        
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val)
             return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};
