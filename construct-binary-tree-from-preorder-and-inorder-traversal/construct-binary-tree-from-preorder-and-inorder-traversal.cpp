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
    int preidx=0;
    TreeNode* treerec(int start,int end,vector<int>& preorder, vector<int>& inorder)
    {
        if(start>end)
            return NULL;
        TreeNode* root=new TreeNode(preorder[preidx++]);
        int idx=0;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==preorder[preidx-1])
            {
                idx=i;
                break;
            }
        }
        root->left=treerec(start,idx-1,preorder,inorder);
        root->right=treerec(idx+1,end,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ipre=preorder.size();
        return treerec(0,ipre-1,preorder,inorder);
    }
};