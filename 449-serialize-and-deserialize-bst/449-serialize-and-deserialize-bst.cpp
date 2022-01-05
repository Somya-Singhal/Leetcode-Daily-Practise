/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        string str="";
        serializehelper(root,str);
        str.pop_back();
        return str;
    }
    
    void serializehelper(TreeNode* root,string& str)
    {
        if(root==NULL)
            return;
        str+=to_string(root->val)+',';
        serializehelper(root->left,str);
        serializehelper(root->right,str);
    }
    
    //method-1
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
       stringstream ss(data);
      vector<int>res;
       while(ss.good()>0)
       {
           string substr;
           getline(ss,substr,',');
           res.push_back(atoi(substr.c_str()));
       }
        int n=res.size();
        return deserializehelper(res,0,n-1);
    }
    TreeNode* deserializehelper(vector<int>& res,int s,int e)
    {
        if(s>e)
            return NULL;
        int index;
        TreeNode* root=new TreeNode(res[s]);
        for(int j=s;j<=e;j++)
        {
            if(res[j]>res[s])
            {
                index=j;
                break;
            }
        }
        root->left=deserializehelper(res,s+1,index-1);
        root->right=deserializehelper(res,index,e);
        return root;
    }
    
    //method-2
//      TreeNode* deserialize(string data) {
//         if(data.length()==0)
//             return NULL;
//        stringstream ss(data);
//        queue<int>q;
//        while(ss.good())
//        {
//            string substr;
//            getline(ss,substr,',');
//            q.push(atoi(substr.c_str()));
//        }

//         return deserializehelper(q,INT_MIN,INT_MAX);
//     }
//     TreeNode* deserializehelper(queue<int>& q,int s,int e)
//     {
//         if(q.empty())
//             return NULL;
//         int top=q.front();
//         if(top<s || top>e)
//             return NULL;
//         q.pop();
//         TreeNode* root=new TreeNode(top);
//         root->left=deserializehelper(q,s,top);
//         root->right=deserializehelper(q,top,e);
//         return root;
//     }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;