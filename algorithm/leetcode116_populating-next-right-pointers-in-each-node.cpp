class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        	return NULL;
        root->next = NULL;
        link(root);
    }
};