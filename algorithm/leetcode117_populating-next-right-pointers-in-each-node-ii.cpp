class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        	return root;
        Node *head = root;
        if(head->left && head->right)
        {
	        head->left->next = head->right;
	    	while(head->next)
	    	{
	    		if(head->next->left)
    			{	
    				head->right->next = head->next->left;
    				break;
    			}
	    		else if(!head->next->left && head->next->right)
	    		{
	    			head->right->next = head->next->right;
	    			break;
	    		}
	    		head = head->next;
	    	}
	    }
	    else if(head->left && !head->right)
	    {
	    	while(head->next)
	    	{
	    		if(head->next->left)
	    		{
	    			head->left->next = head->next->left;
	    			break;
	    		}
	    		else if(!head->next->left && head->next->right)
	    		{
	    			head->left->next = head->next->right;
	    			break;
	    		}
	    		head = head->next;
	    	}
	    }
	    else if(!head->left && head->right)
	    {
	    	while(head->next)
	    	{
	    		if(head->next->left)
	    		{
	    			head->right->next = head->next->left;
	    			break;
	    		}
	    		else if(!head->next->left && head->next->right)
	    		{
	    			head->right->next = head->next->right;
	    			break;
	    		}
	    		head = head->next;
	    	}
	    }
    	connect(root->left);
    	connect(root->right);
        return root;
    }
};
