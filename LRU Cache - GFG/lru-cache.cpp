// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    struct Node
    {
        int d,v;
        struct Node *next,*prev;
        Node(int key,int val)
        {
            d=key;
            v=val;
        }
    };
    
    
    public:
    unordered_map<int,Node*>mp;
    Node *head=new Node(0,0);
    Node *tail=new Node(0,0);
    int c;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        c=cap;
        head->next=tail;
        tail->prev=head;
    }
    void add(Node *temp)
    {
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
    }
    void del(Node *temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete (temp);
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end())
        {
            Node *curr=mp[key];
            int val=curr->v;
            mp.erase(key);
            del(curr);
            add(new Node(key,val));
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(mp.find(key)!=mp.end())
        {
            Node *curr=mp[key];
            mp.erase(key);
            del(curr);
            
        }
        if(mp.size()==c)
        {
            mp.erase(tail->prev->d);
            del(tail->prev);
            
        }
        add(new Node(key,value));
        mp[key]=head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends