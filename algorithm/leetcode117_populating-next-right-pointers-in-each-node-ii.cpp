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
        if(root == NULL)
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
        	}	
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        	return root;
        Node *parent = root, *prev, *tmp;
        while(parent)
        {
        	while(parent && !parent->left && !parent->right)
        		parent = parent->next;//找到第一个有子的节点parent
        	if(parent == NULL)
        		break;
        	prev = NULL;
        	tmp = parent;
        	while(tmp)	//遍历parent层，将其下层连接
        	{
        		if(tmp->left)
        		{
        			if(prev)
        				prev->next = tmp->left;
        			prev = tmp->left;
        		}
        		if(tmp->right)
        		{
        			if(prev)
        				prev->next = tmp->right;
        			prev = tmp->right;
        		}	
        		tmp = tmp->next;
        	}
        	parent = parent->left ? parent->left : parent->right;
        	//parent移向下一层
        }
        return root;
    }
};
