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
            TreeNode *newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *curr=root;
        int currlen=1;
        while(!q.empty() && currlen!=depth)
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(currlen==(depth-1))
                {
                    TreeNode *node1=new TreeNode(val);
                    TreeNode *node2=new TreeNode(val);
                    TreeNode *lstr=temp->left,*rstr=temp->right;
                    temp->left=node1;
                    temp->right=node2;
                    node1->left=lstr,node2->right=rstr;
                }
            }
            
            currlen+=1;
        }
        return root;
    }
};