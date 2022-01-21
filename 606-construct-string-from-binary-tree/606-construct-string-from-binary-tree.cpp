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
    //recursion
//         string str="";
//         if(root==NULL)
//             return str;
//         str+=to_string(root->val);
//         if(root->left && root->right)
//         {
//             str+="("+tree2str(root->left)+")("+tree2str(root->right)+")";
//         }
            
//         if(root->left==NULL && root->right)
//         {
//             str+='(';
//             str+=')';
//             str+='('+tree2str(root->right)+')';
//         }
//         if(root->left && root->right==NULL)
//             str+="("+tree2str(root->left)+")";
//         return str;
    string tree2str(TreeNode* root) {
        //stack
        if(root==NULL)
            return "";
        stack<TreeNode*>s;
        string str="";
        unordered_set<TreeNode*>vis;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr=s.top();
            if(vis.find(curr)!=vis.end())
            {
                s.pop();
                str+=")";
            }
            else
            {
                vis.insert({curr});
                str+="("+to_string(curr->val);
                if(curr->left==NULL && curr->right!=NULL)
                {
                     str+="(";
                     str+=")";
                }
                if(curr->right!=NULL)
                    s.push(curr->right);
                if(curr->left!=NULL)
                    s.push(curr->left);
            }
        }
        return str.substr(1,str.length()-2);
    }    
};