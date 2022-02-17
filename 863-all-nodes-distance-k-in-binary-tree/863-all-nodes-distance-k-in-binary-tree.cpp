/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //using map
    
    // unordered_map<TreeNode*,int>mp;
    // int path(TreeNode* root, TreeNode* target)
    // {
    //     if(root==NULL)
    //         return -1;
    //     if(root==target)
    //     {
    //         mp[root]=0;
    //         return 0;
    //     }
    //         int l=path(root->left,target);
    //         if(l>=0)
    //         {
    //             mp[root]=l+1;
    //             return l+1;
    //         }
    //         int r=path(root->right,target);
    //         if(r>=0)
    //         {
    //             mp[root]=r+1;
    //             return r+1;
    //         }
    //     return -1;
    // }
    // void dfs(TreeNode* root, TreeNode* target,int level,int k,vector<int>& res)
    // {
    //     if(root==NULL)
    //         return;
    //     if(mp.find(root)!=mp.end())
    //     level=mp[root];
    //     if(level==k)
    //     {
    //         res.push_back(root->val);
    //     }
    //     dfs(root->left,target,level+1,k,res);
    //     dfs(root->right,target,level+1,k,res);
    // }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //     vector<int>res;
    //     path(root,target);
    //     dfs(root,target,mp[root],k,res);
    //     return res;
    // }
    
    //using map,dfs and bfs(graph)
    //  unordered_map<int,vector<int>>mp;
    // void graph(TreeNode* child,TreeNode* parent)
    // {
    //     if(parent && child)
    //     {
    //         mp[parent->val].push_back(child->val);
    //         mp[child->val].push_back(parent->val);
    //     }
    //     if(child->left)
    //         graph(child->left,child);
    //     if(child->right)
    //         graph(child->right,child);
    // }
    //  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //     vector<int>res;
    //     graph(root,NULL);
    //      //bfs
    //     queue<int>q;
    //     unordered_set<int>vis;
    //     q.push(target->val);
    //     vis.insert(target->val);
    //     for(int i=0;i<k;i++)
    //     {
    //         int len=q.size();
    //         for(int j=0;j<len;j++)
    //         {
    //             int curr=q.front();
    //             q.pop();
    //             for(auto x:mp[curr])
    //             {
    //                 if(vis.count(x)==0)
    //                 {
    //                     q.push(x);
    //                     vis.insert(x);
    //                 }
    //             }
    //         }
    //     }
    //      while(!q.empty())
    //      {
    //          res.push_back(q.front());
    //          q.pop();
    //      }
    //     return res;
    // }
    
    //without map
    vector<int>res;
    void dfs(TreeNode* root,int k,int depth)
    {
        if(root==NULL) return;
        if(depth==k)
            res.push_back(root->val);
        dfs(root->left,k,depth+1);
        dfs(root->right,k,depth+1);
    }
    int path(TreeNode* root, TreeNode* target, int k)
    {
        if(root==NULL)
            return -1;
        else if(root==target)
        {
            dfs(target,k,0);
            return 1;
        }
        else {
        int l=path(root->left,target,k),r=path(root->right,target,k);
        if(l!=-1)
        {
            if(l==k)
                res.push_back(root->val);
            dfs(root->right,k,l+1);
            return l+1;
        }
        else if(r!=-1)
        {
            if(r==k)
                res.push_back(root->val);
            dfs(root->left,k,r+1);
            return r+1;
        }
        else
           return -1;
        }
    }
     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        path(root,target,k);
        return res;
    }
};