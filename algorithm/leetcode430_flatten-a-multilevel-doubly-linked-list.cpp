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
        Node *tempHead = head;
        Node *cur = head;
        while(cur->child != NULL && cur->next != NULL) 
            cur = cur->next;
        Node *nextNode = cur->next;
        Node *child = flatten(cur->child);
        child->next = nextNode;
        child->prev = cur;
        cur->next = child;
        nextNode->prev = 
    }
};