class listNode
{
public:
    int key, value;
    listNode* next;
    listNode* prev;
    listNode(int k, int v) : key(k), value(v), next(NULL), prev(NULL){}
};
class List
{
public:
    listNode *head, *tail;
    int len;
    List():len(0)
    {
        head = new listNode(0,0);
        tail = new listNode(0,0);
        head->next = tail;
        tail->next = head;
    }
    void addAtHead(listNode* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        len++;
    }
    void delNode(listNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        len--;
    }
    listNode* dellast()
    {
        if(size()==0)
            return NULL;
        listNode* last = tail->prev;
        delNode(last);
        return last;
    }
    int size()
    {
        return len;
    }
};
class LRUCache {
    int cap;
    unordered_map<int,listNode*> key_node;
    List cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!key_node.count(key))
            return -1;
        int val = key_node[key]->value;
        put(key,val);
        return val;
    }
    
    void put(int key, int value) {
        listNode *node = new listNode(key, value);
        if(key_node.count(key))
        {
            cache.delNode(key_node[key]);
            cache.addAtHead(node);
            key_node[key] = node;
        }
        else
        {
            if(cap == cache.size())
            {
                listNode *last = cache.dellast();
                key_node.erase(last->key);
            }
            cache.addAtHead(node);
            key_node[key] = node;
        }
    }
};

class LRUCache {
    list<int> cache;
    int cap;
    unordered_map<int,int> kv;
    unordered_map<int,list<int>::iterator> kPos;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key))
            return -1;
        put(key,kv[key]);
        return kv[key];
    }
    
    void put(int key, int value) {
        if(kv.count(key))
        {
            cache.erase(kPos[key]);
            cache.push_front(key);
            kPos[key] = cache.begin();
            kv[key] = value;
        }
        else
        {
            if(cap == cache.size())
            {
                int lastkey = cache.back();
                cache.pop_back();
                kv.erase(lastkey);
            }
            kv[key] = value;
            cache.push_front(key);
            kPos[key] = cache.begin();
        }
    }
};