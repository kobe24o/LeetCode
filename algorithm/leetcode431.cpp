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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return NULL;
        TreeNode* newroot = new TreeNode(root->val);
        TreeNode* cur = NULL;
        if(!root->children.empty())
        {
            newroot->left = encode(root->children[0]);
            cur = newroot->left;
        }
        for(int i = 1; i < root->children.size(); ++i)
        {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return newroot;
    }
    
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node *newroot = new Node(root->val);
        TreeNode *cur = NULL;
        if(root->left)
        {
            newroot->children.push_back(decode(root->left));
            cur = root->left;
        }
        while(cur && cur->right)
        {
            newroot->children.push_back(decode(cur->right));
            cur = cur->right;
        }
        return newroot;
    }
};

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return NULL;
        TreeNode* newroot = new TreeNode(root->val), *newTreeNode = NULL;
        TreeNode* cur = NULL;
        queue<pair<Node*, TreeNode*>> q;
        q.push({root,newroot});
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                root = q.front().first;
                newTreeNode = q.front().second;
                q.pop();
                if(!root->children.empty())
                {
                    newTreeNode->left = new TreeNode(root->children[0]->val);
                    cur = newTreeNode->left;
                    q.push({root->children[0], cur});
                }
                for(int i = 1; i < root->children.size(); ++i)
                {
                    cur->right = new TreeNode(root->children[i]->val);;
                    cur = cur->right;
                    q.push({root->children[i], cur});
                }
            }
        }
        return newroot;
    }
    
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node *newroot = new Node(root->val), *newNode = NULL;
        Node *cur = NULL;
        queue<pair<TreeNode*, Node*>> q;
        q.push({root,newroot});
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                root = q.front().first;
                cur = q.front().second;
                q.pop();
                if(root->left)
                {
                    newNode = new Node(root->left->val);
                    cur->children.push_back(newNode);
                    q.push({root->left, newNode});
                    root = root->left;
                    while(root->right)
                    {
                        newNode = new Node(root->right->val);
                        cur->children.push_back(newNode);
                        q.push({root->right, newNode});
                        root = root->right;
                    }
                }
            }
        }
        return newroot;
    }
};