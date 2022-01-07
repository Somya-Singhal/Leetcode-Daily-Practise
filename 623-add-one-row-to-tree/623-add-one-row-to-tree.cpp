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
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*>q;
        q.push(root);
        int currdepth=1;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(currdepth>=depth)
                    return root;
                if(currdepth==depth-1)
                {
                    TreeNode *newroot1=new TreeNode(val),*newroot2=new TreeNode(val);
                     if(curr->left)
                         newroot1->left=curr->left;
                     if(curr->right)
                         newroot2->right=curr->right;
                     curr->left=newroot1;
                     curr->right=newroot2;
                   
                }
                else 
                {
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }  
            }
            currdepth++;
        }
        return root;
    }
};