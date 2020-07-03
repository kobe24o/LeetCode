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
    Node* cloneTree(Node* root) {
        if(!root) return root;
        Node* r = new Node(root->val)
        for(auto it : root->children)
        {
            Node* child = cloneTree(it);
            r->children.push_back(child);
        }
        return r;
    }
};

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root) return root;
        Node* r = new Node(root->val);
        queue<Node*> q, qc;
        q.push(root);
        qc.push(r);
        Node* cur, *cur_, *c;
        while(!q.empty())
        {
            cur = q.front();
            cur_ = qc.front();
            q.pop();
            qc.pop();
            for(auto it : cur->children)
            {
                if(!it)
                {
                    cur_->children.push_back(NULL);
                    continue;
                }
                q.push(it);
                c = new Node(it->val);
                cur_->children.push_back(c);
                qc.push(c);
            }
        }
        return r;
    }
};