class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL)
        	return root;
        root->left->next = root->right;
    	if(root->next != NULL)
    		root->right->next = root->next->left;
    	connect(root->left);
    	connect(root->right);
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL)
        	return root;
        queue<Node*> q;
        q.push(root);
        Node *p, *prev, *cur;
        int n;
        while(!q.empty())
        {
        	n = q.size();
        	while(n--)
        	{
        		p = q.front();
	        	if(p->left != NULL)
	        	{
	        		q.push(p->left);
	        		q.push(p->right);
		        	p->left->next = p->right;
			    	if(p->next != NULL)
			    		p->right->next = p->next->left;
			    }
	        	q.pop();
        	}	
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL)
        	return root;
        Node *parent = root, *lvfirst, *prev;
        while(parent != NULL)
        {
        	lvfirst = parent->left;
        	if(lvfirst != NULL)
        	{
        		while(parent)
	        	{
	        		parent->left->next = parent->right;
	        		prev = parent->right;
	        		parent = parent->next;
	        		if(parent)
	        			prev->next = parent->left;
	        	}
        	}
        	parent = lvfirst;	
        }
        return root;
    }
};