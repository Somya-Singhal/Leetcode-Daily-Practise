// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *a=head1,*b=head2,*start=NULL,*prev=NULL;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            a=a->next;
        }
        else if(b->data<a->data)
        b=b->next;
        else
        {
            Node *newnode=new Node(a->data);
            if(start==NULL)
            {
                start=newnode;
                prev=newnode;
            }
            else
            {
                prev->next=newnode;
                prev=newnode;
            }
            a=a->next;
            b=b->next;
        }
       
    }
     prev->next=NULL;
        return start;
}