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
    TreeNode* inpostrec(int s,int e,vector<int>& inorder, vector<int>& postorder,int ps,int pe)
    {
        if(s>e || ps>pe)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int mid;
        for(int i=s;i<=e;i++)
        {
            if(inorder[i]==root->val)
            {
                mid=i;
                break;
            }
        }
        root->left=inpostrec(s,mid-1,inorder,postorder,ps,ps+mid-s-1);
        root->right=inpostrec(mid+1,e,inorder,postorder,ps+mid-s,pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0)
            return 0;
        int n=postorder.size();
        return inpostrec(0,n-1,inorder,postorder,0,n-1);
    }
};