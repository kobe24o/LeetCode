class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *prev = NULL, *tp, *head = NULL;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	tp = stk.top();
        	stk.pop();
        	tp->left = NULL;
        	if(prev)
        		prev->right = tp;
    		if(!head)
    			head = tp;
    		prev = tp;
    		root = tp->right;
        }
        return head;
    }
};

class Solution {
	TreeNode* prev = NULL;
	TreeNode* head = NULL;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root)
        	return NULL;
        convertBiNode(root->left);
        if(prev)
        	prev->right = root;
        prev = root;
        root->left = NULL;
        if(!head)
        {
        	head = root;
        	prev = root;
        }
        convertBiNode(root->right);
        return head;
    }
};