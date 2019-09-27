/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        unordered_map<Node*, Node*> m;
        Node *cur = head, *newNode;
        while(cur != NULL)
        {
            newNode = new Node(cur->val);
            m[cur] = newNode;
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL)
        {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};