class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode(int x) : val(x), next(NULL), prev(NULL){}
};

class LRUCache {
	int cap;
	int size = 0;
	unordered_map<int,ListNode*> key_node;
	unordered_map<ListNode*,int> node_key;
	ListNode* emptyHead;
	ListNode* tail;
public:
    LRUCache(int capacity) {
    	cap = capacity;
    	emptyHead = new ListNode(0);
    	tail = emptyHead;
    }
    
    int get(int key) {
    	if(!key_node.count(key))
    		return -1;
    	
    }
    
    void put(int key, int value) {
    	if(size < cap)
    	{
    		ListNode *node = new ListNode(value);
    		key_node[key] = node;
    		node_key[node] = key;
    		size++;
    		if(emptyHead->next)
    			emptyHead->next->prev = node;
    		node->next = emptyHead->next;
    		if(!node->next)
    			tail = node;
    	}
    	else
    	{
    		tail = tail->prev;
    		delete tail->next;
    		tail->next = NULL;
    		size--;
    		put(key,value);
    	}
    }
};