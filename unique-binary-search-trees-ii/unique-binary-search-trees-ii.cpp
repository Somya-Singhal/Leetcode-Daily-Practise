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
    vector<TreeNode*> Treerec(int i,int n)
    {
        if(i>n)
        {
            vector<TreeNode*>list;
            list.push_back(NULL);
            return list;
        }
        vector<TreeNode*>res;
        for(int s=i;s<=n;s++)
        {
            vector<TreeNode*>l=Treerec(i,s-1);
            vector<TreeNode*>r=Treerec(s+1,n);
            for(auto x:l)
            {
                for(auto y:r)
                {
                    TreeNode* root=new TreeNode(s);
                    root->left=x;
                    root->right=y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Treerec(1,n);
    }
};