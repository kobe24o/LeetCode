/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node->right)
        //右节点比其大，没有右节点,那就查上面的多层祖父节点
        {
            int v = node->val;
            while(node->parent && node->parent->val < v)
            {
                node = node->parent;
            }
            return node->parent;
        }
        Node* cur = node->right, *prev = NULL;
        while(cur)
        {
        	prev = cur;
        	cur = cur->left;
        }
        return prev;
    }
};