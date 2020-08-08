/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *newnode = new Node(insertVal);
        Node* biggest = head, *cur = head;
        int biggestVal = head->val;
        while(true)
        {
            if(cur->val <= insertVal && cur->next->val >= insertVal)
            {
                newnode->next = cur->next;
                cur->next = newnode;
                return head;
            }
            if(cur->val >= biggestVal)
            {
                biggestVal = cur->val;
                biggest = cur;
            }
            if(cur->next == head)//转了一圈了
                break;
            cur = cur->next;
        }
        newnode->next = biggest->next;//插入的是最大值或最小值
        biggest->next = newnode;
        return head;
    }
};