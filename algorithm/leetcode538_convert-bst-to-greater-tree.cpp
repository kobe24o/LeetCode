class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        int prevSum = 0;
        TreeNode* rootcopy = root;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->right;
        	}
        	root = stk.top();
        	prevSum += root->val;
        	root->val = prevSum;
        	root = root->left;
        	stk.pop();
        }
        return rootcopy;
    }
};