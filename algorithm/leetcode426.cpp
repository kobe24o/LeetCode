/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        stack<Node*> stk;
        Node *cur, *head = NULL, *prev = NULL;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            cur = stk.top();
            stk.pop();
            if(!head)
                head = cur;
            root = cur->right;
            cur->left = prev;
            if(prev)
                prev->right = cur;
            prev = cur;
        }
        cur->right = head;
        head->left = cur;
        return head;
    }
};