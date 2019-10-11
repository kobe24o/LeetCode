class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        	return root;
        Node *head = root;
        if(root->left)
        {
        	if(root->right)
        		root->left->next = root->right;
        	else
        		root->left->next = findchild(root);
        }
        if(root->right)
        	root->right->next = findchild(root);
	    connect(root->right);
    	connect(root->left); 	
        return root;
    }
    Node* findchild(Node* root) 
    {
    	if(root->next == NULL)
    		return NULL;
    	while(root->next)
    	{
    		if(root->next->left)
    			return root->next->left;
    		if(root->next->right)
    			return root->next->right;
    		root = root->next;
    	}
    	return NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL)
        	return root;
        queue<Node*> q;
        q.push(root);
        Node *p;
        int n;
        while(!q.empty())
        {
        	n = q.size();
        	while(n--)
        	{
        		p = q.front();
        		q.pop();
        		if(n)
	        		p->next = q.front();
        		if(p->left)
        			q.push(p->left);
        		if(p->right)
        			q.push(p->right);
	        	// p->next = n == 0 ? NULL : q.front();
        	}	
        }
        return root;
    }
};
