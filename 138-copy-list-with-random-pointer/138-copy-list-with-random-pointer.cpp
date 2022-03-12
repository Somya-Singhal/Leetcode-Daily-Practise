/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node *newlist=NULL,*curr=head;
        while(curr!=NULL)
        {
            Node *newnode=new Node(curr->val);
            newnode->next=curr->next;
            curr->next=newnode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->random!=NULL)
               curr->next->random=curr->random->next;
            else
                curr->next->random=NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node *newhead=head->next,*temp=NULL;
        while(curr!=NULL)
        {
           temp=curr->next->next; 
           if(temp!=NULL)
           curr->next->next=curr->next->next->next;
           else
               curr->next->next=NULL;
           curr->next=temp;
           curr=curr->next;
        }
        return newhead;
    }
};