// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL || head->next==NULL)
        return head;
        Node *zerod=new Node(0),*oned=new Node(0),*twod=new Node(0);
        Node *a=zerod,*b=oned,*c=twod,*temp=head;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                    a->next=temp;
                     a=a->next;
           
            }
            else if(temp->data==1)
            {
               
                    b->next=temp;
                     b=b->next;
            
            }
            else
            {
              
                    c->next=temp;
                    c=c->next;
              
            }
            temp=temp->next;
        }
        a->next=(oned->next)?(oned->next):(twod->next);
        b->next=twod->next;
        c->next=NULL;
        head=zerod->next;
        delete zerod;
        delete oned;
        delete twod;
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends