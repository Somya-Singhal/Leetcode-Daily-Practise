// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
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
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *root=reverseLL(head);
        int num=1;
        int carry=0;
        Node *start=NULL,*prev=NULL;
        while(root!=NULL)
        {
            int n=root->data+carry+num;
            num=0;
            if(n>9)
            {
                carry=n/10;
                n=n%10;
            }
            else
            carry=0;
            if(start==NULL)
            {
                start=root;
            }
            root->data=n;
            prev=root;
            root=root->next;
        }
        if(carry)
        {
            Node *newnode=new Node(carry);
            prev->next=newnode;
            prev=newnode;
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends