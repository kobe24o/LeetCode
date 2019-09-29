class node
{
public:
    int val;
    node *next;
    node(int v):val(v),next(NULL) {}
};
class MyLinkedList {
    node *head, *tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= len || index < 0)
            return -1;
        node *cur = head;
        while(index--)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {  
        node *h = new node(val);
        h->next = head;
        head = h;
        if(len == 0)
            tail = head;
        ++len;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *t = new node(val);
        if(len == 0)
        {
            head = tail = t;
        }
        else
        {
            tail->next = t;
            tail = t;
        }
        ++len; 
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == len)
            addAtTail(val);
        else if(index <= 0)
            addAtHead(val);
        else if(index > len)
            return;
        else
        {
            node *cur = head;
            while(--index)
                cur = cur->next;
            node *newNode = new node(val);
            newNode->next = cur->next;
            cur->next = newNode;
            ++len;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len || index < 0)
            return;
        --len;
        node *virtualheadNode, *del, *cur;
        virtualheadNode = new node(0);
        virtualheadNode->next = head;
        cur = virtualheadNode;
        while(index--)
        {
            cur = cur->next;
        }
        del = cur->next;
        cur->next = cur->next->next;
        delete del;
        head = virtualheadNode->next;
        if(cur->next == NULL)
            tail = cur;
        delete virtualheadNode;
    }
};
//以下双链表
class node
{
public:
    int val;
    node *next;
    node *prev;
    node(int v):val(v),next(NULL),prev(NULL) {}
};
class MyLinkedList {
    node *head, *tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= len || index < 0)
            return -1;
        node *cur = head;
        while(index--)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {  
        node *h = new node(val);
        h->next = head;
        head = h;
        if(len == 0)
            tail = head;
        ++len;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *t = new node(val);
        if(len == 0)
        {
            head = tail = t;
        }
        else
        {
            tail->next = t;
            t->prev = tail;
            tail = t;
        }
        ++len; 
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == len)
            addAtTail(val);
        else if(index <= 0)
            addAtHead(val);
        else if(index > len)
            return;
        else
        {
            node *cur = head;
            while(--index)
                cur = cur->next;
            node *newNode = new node(val);
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next->prev = newNode;
            cur->next = newNode;
            ++len;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len || index < 0)
            return;
        --len;
        node *virtualheadNode, *del, *cur;
        virtualheadNode = new node(0);
        virtualheadNode->next = head;
        head->prev = virtualheadNode;
        cur = virtualheadNode;
        while(index--)
        {
            cur = cur->next;
        }
        del = cur->next;
        cur->next = cur->next->next;
        if(del->next) 
            del->next->prev = cur;
        delete del;
        head = virtualheadNode->next;
        if(cur->next == NULL)
            tail = cur;
        delete virtualheadNode;
    }
};