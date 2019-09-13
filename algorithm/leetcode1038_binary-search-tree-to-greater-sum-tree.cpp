class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> stk;
        int sum = 0;
        TreeNode *rootcopy = root;
        while(root || !stk.empty()) 
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->right;
        	}
        	sum += stk.top()->val;
        	stk.top()->val = sum;
        	root = stk.top()->left;
        	stk.pop();
        }
        return rootcopy;
    }
};