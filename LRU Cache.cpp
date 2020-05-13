class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key,int value)
        {
            this->key=key;
            this->value=value;
            prev=NULL;
            next=NULL;
        }
};
class LRUCache {
public:
    int cap1;
    unordered_map<int, Node*>m1;
    Node* head=NULL;
    Node* tail=NULL;
    LRUCache(int capacity) {
        this->cap1=capacity;
    }
    void add(Node** node)
    {
        Node* temp;
        temp=*node;
        if(head==NULL && tail==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {temp->next=head;
         head->prev=temp;
        head=temp;
         return;
        }
    }
    void remove1(Node** node)
    {
        Node* temp;
        temp=*node;
        if(head==tail)
        {head=tail=NULL;
        }
        else if(temp->next==NULL)
        {       (temp->prev)->next=NULL;
             tail=temp->prev;
    }
        else if(temp->prev==NULL)
        {(temp->next)->prev=NULL;
                  head=temp->next;}
        else{
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
        }
        delete(temp);
        return;
    }
    
    int get(int key) {
        if(m1.find(key)!=m1.end())
        {
            Node* node=m1[key];
            int res=node->value;
            remove1(&node);
            Node* node1=new Node(key,res);
            add(&node1);
            m1[key]=node1;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(m1.find(key)!=m1.end())
            {
                Node* node=m1[key];
                 remove1(&node);
            }
            else if(m1.size()==cap1)
               {
                int e1=tail->key;
                   remove1(&tail);
                   m1.erase(e1);
               }
              Node* node=new Node(key,value);
              m1[key]=node;  
              add(&node); 
            }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
