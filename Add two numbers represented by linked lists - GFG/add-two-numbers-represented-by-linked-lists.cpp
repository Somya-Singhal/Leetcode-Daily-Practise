// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseLL(Node *head)
    {
        Node *curr=head,*next=NULL,*prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *f=reverseLL(first);
        Node *s=reverseLL(second);
        Node *start=NULL,*prev=NULL;
        int carry=0;
        while(f!=NULL || s!=NULL)
        {
            int num=(f==NULL)?0:f->data;
            num+=(s==NULL)?0:s->data;
            num+=carry;
            if(num>9)
            {
                carry=num/10;
                num=num%10;
            }
            else
            carry=0;
            Node *newnode=new Node(num);
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
            if(f) f=f->next;
            if(s) s=s->next;
        }
        if(carry)
        {
            Node *extra=new Node(carry);
            prev->next=extra;
            prev=extra;
        }
        start=reverseLL(start);
        return start;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends