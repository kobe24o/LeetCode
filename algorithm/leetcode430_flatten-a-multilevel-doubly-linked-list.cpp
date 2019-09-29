/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        
        Node *cur = head, *nextNode = NULL, *prevN = head;
        while(prevN)
        {
            if(cur && cur->child) 
            {
                nextNode = cur->next;
                cur->next = flatten(cur->child);
                cur->child->prev = cur;
                cur->child = NULL;
            }
            prevN = cur;
            if(cur)
                cur = cur->next;
            if(!cur && nextNode)
            {
                prevN->next = nextNode;
                nextNode->prev = prevN;
                cur = prevN->next;
                nextNode = NULL;
            }
        }
        return head;
    }
};