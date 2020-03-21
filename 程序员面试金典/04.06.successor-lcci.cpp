class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	if(!root || !p)
    		return NULL;
    	stack<TreeNode*> stk;
    	TreeNode *tp;
    	bool found = false;
    	while(root || !stk.empty())
    	{
    		while(root)
    		{
    			stk.push(root);
    			root = root->left;
    		}
    		tp = stk.top();
    		stk.pop();
    		if(found)
    			return tp;
    		if(tp == p)
    			found = true;
    		root = tp->right;
    	}
    	return NULL;
    }
};