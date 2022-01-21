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
    string tree2str(TreeNode* root) {
//         TreeNode* curr=root;
//         stack<TreeNode*>s;
//         string str;
//         while(curr!=NULL || !s.empty())
//         {
//             while(curr!=NULL)
//             {
//                 str+='(';
//                 s.push(curr);
//                 str+=to_string(curr->val);
//                 curr=curr->left;
//             }
//             curr=s.top();
//             s.pop();
//             if(curr->right!=NULL)
//             {
                
//                 str+='(';
//                 str+=')';
//             }
//             else
//                 str+=')';
//             curr=curr->right;
//         }
//         return str.substr(1,str.length()-1);
        string str="";
        if(root==NULL)
            return str;
        str+=to_string(root->val);
        if(root->left && root->right)
        {
            str+='('+tree2str(root->left)+')';
            str+='('+tree2str(root->right)+')';
        }
            
        if(root->left==NULL && root->right)
        {
            str+='(';
            str+=')';
            str+='('+tree2str(root->right)+')';
        }
        if(root->left && root->right==NULL)
            str+='('+tree2str(root->left)+')';
        return str;
    }
};