// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void findmid(Node *head,Node **s1,Node **s2)
    {
        Node *slow=head,*fast=head->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        
        *s2=slow->next;
        slow->next=NULL;
        *s1=head;
    }
    Node* merge(Node *a,Node *b)
    {
        Node *result=NULL;
        if(b==NULL)
        return (a);
        if(a==NULL)
        return (b);
        if(a->data<=b->data)
        {
            result=a;
            result->next=merge(a->next,b);
        }
        else
        {
            result=b;
            result->next=merge(a,b->next);
        }
        return (result);
    }
    void split(Node **headref)
    {
     
        Node *head=*headref;
        Node *a,*b;
        if(head==NULL || head->next==NULL)
        return;
        findmid(head,&a,&b);
        split(&a);
        split(&b);
        *headref=merge(a,b);
    }
    Node* mergeSort(Node* head) {
        // your code here
        split(&head);
        return head;
    }
};// 


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends