// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int x)
    {
       data=x;
       left=right=NULL;
    }
};
class Solution{
    public:
    Node* insert(Node* root,int data,int *succ)
    {
        if(root==NULL)
        return new Node(data);
        else if(root->data>data)
        {
            *succ=root->data;
            root->left=insert(root->left,data,succ);
        }
        else
        root->right=insert(root->right,data,succ);
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>res(n,-1);
        Node* root=NULL;
        for(int i=n-1;i>=0;i--)
        {
            int val=-1;
            root=insert(root,arr[i],&val);
            res[i]=val;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends