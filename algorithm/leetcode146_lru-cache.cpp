class Node
{
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v):prev(NULL),next(NULL)
    {
        key = k;
        value = v;
    }
};
class DoubleList
{
    Node *head, *tail;
    int len;
public:
    DoubleList():len(0)
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void addAtHead(Node* newnode)
    {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        len++;
    }

    void delNode(Node *del)
    {
        del->prev->next = del->next;
        del->next->prev = del->prev;
        len--;
    }

    Node* delLast()//删除最后的节点，并返回该节点
    {
        if(tail->prev == head)
            return NULL;
        Node *last = tail->prev;
        delNode(last);
        return last;
    }
    int size()
    {
        return len;
    }

};
class LRUCache {
    unordered_map<int, Node*> m;
    DoubleList cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        int val = m[key]->value;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        Node *newnode = new Node(key,value);
        if(m.find(key) != m.end())//找到节点，移至前面
        {
            cache.delNode(m[key]);
            cache.addAtHead(newnode);
            m[key] = newnode;
        }
        else//没找到key
        {
            if(cap == cache.size())
            {
                Node *last = cache.delLast();
                m.erase(last->key);
            }
            cache.addAtHead(newnode);
            m[key] = newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */