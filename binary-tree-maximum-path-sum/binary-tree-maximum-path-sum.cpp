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
//     int PathSumrec(TreeNode* root,int *maxSum)
//     {
//         if(root==NULL)
//             return 0;
//         int left=max(PathSumrec(root->left,maxSum),0);
//         int right=max(PathSumrec(root->right,maxSum),0);
//         int currpathsum=root->val+left+right;
//         *maxSum=max(*maxSum,currpathsum);
//         return root->val+max(left,right);
//     }
//     int maxPathSum(TreeNode* root) {
//         int maxSum=INT_MIN;
//         PathSumrec(root,&maxSum);
//         return maxSum;
//     }
    int maxpathsum=INT_MIN;
    int PathSumrec(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=max(PathSumrec(root->left),0);
        int right=max(PathSumrec(root->right),0);
        int currpathsum=root->val+left+right;
        maxpathsum=max(maxpathsum,currpathsum);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        PathSumrec(root);
        return maxpathsum;
    }
};
