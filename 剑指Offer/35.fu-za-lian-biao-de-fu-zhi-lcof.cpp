class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* cur = head, *newNode;
        while(cur)
        {
        	newNode = new Node(cur->val);
        	m[cur] = newNode;
        	cur = cur->next;
        }
        cur = head;
        while(cur)
        {
        	m[cur]->next = m[cur->next];
        	m[cur]->random = m[cur->random];
        	cur = cur->next;
        }
        return m[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* cur = head, *newNode, *H;
        while(cur)//复制一遍原链表 a a` b b`... 
        {
        	newNode = new Node(cur->val);
        	newNode->next = cur->next;
        	cur->next = newNode;
        	cur = newNode->next;
        }
        cur = head;
        newNode = cur->next;
        while(cur)//把新链表的random接好
        {
            if(cur->random)
        	    newNode->random = cur->random->next;
        	cur = cur->next->next;
            if(cur)
        	    newNode = cur->next;
        }
        cur = head;
        H = newNode = cur->next;
        while(newNode->next)//两条链表拆开
        {
            cur->next = newNode->next;
        	newNode->next = newNode->next->next;
            cur = cur->next;
        	newNode = newNode->next;
        }
        cur->next = NULL;
        return H;
    }
};