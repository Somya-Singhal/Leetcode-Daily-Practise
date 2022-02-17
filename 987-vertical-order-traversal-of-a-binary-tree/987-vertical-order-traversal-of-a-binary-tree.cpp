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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int len=q.size();
            map<int,multiset<int>>mp2;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front().first;
                int depth=q.front().second;
                mp2[depth].insert(curr->val);
                q.pop();
                if(curr->left)
                    q.push({curr->left,depth-1});
                if(curr->right)
                    q.push({curr->right,depth+1});
            }
            for(auto x: mp2)
            {
                for(auto it=x.second.begin();it!=x.second.end();it++)
                {
                    mp[x.first].push_back(*it);
                }  
            }
        }
        for(auto &x:mp)
            res.push_back(x.second);
        return res;
    }
};