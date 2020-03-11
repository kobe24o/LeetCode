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
            return NULL;
        bool foundHead = false;
        Node* head, *prev = NULL;
        stack<Node*> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            if(!foundHead)
            {
                head = s.top();
                foundHead = true;
            }
            if(prev)
            {
                prev->left = s.top();
                s.top()->right = prev;
            }
            prev = s.top();
            root = s.top()->right;
            s.pop();
        }
        head->right = prev;
        prev->left = head;
        return head;
    }

};

class Solution {
    Node *head = NULL, *prev = NULL, *tail = NULL;
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return NULL;
        inorder(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
    void inorder(Node* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(!prev)
            head = root;
        else
            prev->right = root;
        root->left = prev;
        prev = root;
        tail = root;
        inorder(root->right);
    }
};