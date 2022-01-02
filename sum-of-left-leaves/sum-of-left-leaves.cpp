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
   
   //using stack
    // int sumOfLeftLeaves(TreeNode* root) {
    //     int ans=0;
    //    stack<TreeNode*>s;
    //    s.push(root);
    //     while(!s.empty())
    //     {
    //        TreeNode* curr=s.top();
    //        s.pop();
    //        if(curr->right!=NULL)
    //            s.push(curr->right);
    //        if(curr->left!=NULL && curr->left->left==NULL && curr->left->right==NULL)
    //            ans+=curr->left->val;
    //        else if(curr->left!=NULL)
    //         s.push(curr->left);
    //     }
    //     return ans;
    // }
     
    //  int sumOfLeftLeaves(TreeNode* root) {
    //    if(root==NULL)
    //        return 0;
    //      int ans=0;
    //      queue<TreeNode*>q;
    //      q.push(root);
    //      while(!q.empty())
    //      {
    //          int len=q.size();
    //          for(int i=0;i<len;i++)
    //          {
    //              TreeNode* curr=q.front();
    //              q.pop();
    //              if(curr->left && curr->left->left==NULL && curr->left->right==NULL)
    //                  ans+=curr->left->val;
    //              else if(curr->left)
    //                  q.push(curr->left);
    //              if(curr->right)
    //                  q.push(curr->right);
    //          }
    //      }
    //      return ans;
    // }
     int sumOfLeftLeaves(TreeNode* root) {
         if(root==NULL)
             return 0;
       if(root->left==NULL && root->right==NULL)
          return 0;
       int ans=0;
       if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
           ans+=root->left->val;
       ans+=sumOfLeftLeaves(root->left);
       ans+=sumOfLeftLeaves(root->right);
       return ans;
     }
};
