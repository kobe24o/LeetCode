/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
    	if(!root) return NULL;
        NodeCopy* newroot = new NodeCopy(root->val);
        build(root, newroot);
        connect(root, newroot, root, newroot);
        return newroot;
    }

    void build(Node* root, NodeCopy* newroot)
    {
    	if(root->left)
    	{
    		NodeCopy* l = new NodeCopy(root->left->val);
    		newroot->left = l;
    		build(root->left, l);
    	}
    	if(root->right)
    	{
    		NodeCopy* r = new NodeCopy(root->right->val);
    		newroot->right = r;
    		build(root->right, r);
    	}
    }

    void connect(Node* root, NodeCopy* newroot, Node* cur1,  NodeCopy* cur2)
    {
    	if(!cur1) return;
    	if(cur1->random)
    		cur2->random = find(root, newroot, cur1->random);
    	connect(root, newroot, cur1->left, cur2->left);
    	connect(root, newroot, cur1->right, cur2->right);
    }

    NodeCopy* find(Node* root, NodeCopy* newroot, Node* rd)
    {
    	if(!root) return NULL;
    	if(root == rd) return newroot;
    	auto l = find(root->left, newroot->left, rd);
    	if(l) return l;
    	auto r = find(root->right, newroot->right, rd);
    	return r;
    }
};

class Solution {
	unordered_map<Node*,NodeCopy*> m;
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
    	if(!root) return NULL;
        NodeCopy* newroot = new NodeCopy(root->val);
        m[root] = newroot;
        build(root, newroot);
        connect(root, newroot);
        return newroot;
    }

    void build(Node* root, NodeCopy* newroot)
    {
    	if(root->left)
    	{
    		NodeCopy* l = new NodeCopy(root->left->val);
    		newroot->left = l;
    		m[root->left] = l;
    		build(root->left, l);
    	}
    	if(root->right)
    	{
    		NodeCopy* r = new NodeCopy(root->right->val);
    		newroot->right = r;
    		m[root->right] = r;
    		build(root->right, r);
    	}
    }

    void connect(Node* root, NodeCopy* newroot)
    {
    	if(!root) return;
    	if(root->random)
    		newroot->random = m[root->random];
    	connect(root->left, newroot->left);
    	connect(root->right, newroot->right);
    }
};