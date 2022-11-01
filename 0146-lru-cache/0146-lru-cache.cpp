class LRUCache {
public:
    
    class ListNode{
      public:
      int val,key;  
      ListNode *pre,*next;
    };
    
    void addnode(ListNode *node)
    {
        ListNode *curr=head->next;
        head->next=node;
        node->pre=head;
        node->next=curr;
        curr->pre=node;
    }
    void removenode(ListNode *node)
    {
        ListNode *prev=node->pre;
        ListNode *succ=node->next;
        prev->next=succ;
        succ->pre=prev;
    
    }
    void moveToHead(ListNode *node)
    {
        removenode(node);
        addnode(node);
    }
    ListNode *removeTail()
    {
        ListNode *curr=tail->pre;
        removenode(curr);
        return curr;
    }
     unordered_map<int,ListNode*>HashMap;
     ListNode *head,*tail;
     int cap,count;
    LRUCache(int capacity) {
        cap=capacity,count=0;
        head=new ListNode();
        tail=new ListNode();
        head->next=tail;
        tail->pre=head;
        head->pre=tail->next=NULL;
    }
    
    int get(int key) {
        ListNode *curr=HashMap[key];
        if(curr==NULL)
            return -1;
        moveToHead(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        ListNode *curr=HashMap[key];
        if(curr==NULL)
        {
            ListNode *newnode=new ListNode();
            newnode->val=value;
            newnode->key=key;
            HashMap[key]=newnode;
            count+=1;
            addnode(newnode);
            if(count>cap)
            {
                ListNode *ptr=removeTail();
                HashMap.erase(ptr->key);
                count-=1;
            }
        }
        
        else
        {
            curr->val=value;
            moveToHead(curr);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */