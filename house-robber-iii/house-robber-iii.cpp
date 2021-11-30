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

//recursive
    /*
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
       return max(root->val+(root->left?rob(root->left->left)+rob(root->left->right):0)+(root->right?rob(root->right->left)+rob(root->right->right):0),rob(root->left)+rob(root->right));
    } 
    */
struct housepair{
    int withoutrobbery=0;
    int withrobbery=0;
};
class Solution {
public:
    
    // dp
    housepair* robdp(TreeNode* root)
    {
        if(root==NULL)
            return new housepair();
        
        housepair* left=robdp(root->left);
        housepair* right=robdp(root->right); 
        housepair* ans=new housepair();
        ans->withrobbery=left->withoutrobbery+root->val+right->withoutrobbery;
        ans->withoutrobbery=max(left->withrobbery,left->withoutrobbery)+max(right->withrobbery,right->withoutrobbery);
        return ans;
    }
    int rob(TreeNode* root) {
      housepair* res=robdp(root);
      return max(res->withoutrobbery,res->withrobbery);
      
    }
};