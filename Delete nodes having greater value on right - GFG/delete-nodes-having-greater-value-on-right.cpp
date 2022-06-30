// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverseLL(Node *head)
    {
        Node *curr=head,*prev=NULL,*nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node *newhead=reverseLL(head);
        Node *temp=newhead->next;
        Node *prev=newhead;
        int cmax=newhead->data;
        while(temp!=NULL)
        {
            if(temp->data<cmax)
            {
                Node *ptr=temp;
                prev->next=temp->next;
            }
            else
            prev=temp;
             cmax=max(cmax,temp->data);
            temp=temp->next;
           
        }
        Node *start=reverseLL(newhead);
        return start;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends