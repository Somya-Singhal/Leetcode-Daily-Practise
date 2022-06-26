// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	struct MinNode{
	    unsigned freq;
	    char data;
	    MinNode *left,*right;
	    MinNode(char data,unsigned freq){
	        left=right=NULL;
	        this->freq=freq;
	        this->data=data;
	    }
	};
	struct compare {
	    bool operator()(MinNode *l,MinNode *r){
	        return (l->freq>r->freq);
	    }
	};
	void codes(MinNode *root,vector<string>& res,string str)
	{
	   // cout<<str<<" ";
	    if(root==NULL)
	     return;
	   
	    if(root->data!='$')
	    {
	        res.push_back(str);
	        return;
	    }
	    codes(root->left,res,str+'0');
	    codes(root->right,res,str+'1');
	    
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    struct MinNode *left,*right,*top;
		    priority_queue<MinNode*,vector<MinNode*>,compare>pq;
		    for(int i=0;i<N;i++)
		    {
		        pq.push(new MinNode(S[i],f[i]));
		    }
		    while(pq.size()!=1)
		    {
		        left=pq.top();
		        pq.pop();
		        right=pq.top();
		        pq.pop();
		        top=new MinNode('$',left->freq+right->freq);
		        top->left=left;
		        top->right=right;
		        pq.push(top);
		    }
		    vector<string>res;
		    codes(pq.top(),res,"");
		    return res;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends