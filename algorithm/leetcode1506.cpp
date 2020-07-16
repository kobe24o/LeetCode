/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int XOR = 0;
        for(Node* root : tree) 
        {
            XOR ^= root->val;
            for(Node* child : root->children)
                XOR ^= child->val;
        }
        for(Node* root : tree)
        {
            if(XOR == root->val)
                return root;
        }
        return NULL;
    }
};