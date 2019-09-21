class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        bool getroot = false;
        stack<TreeNode*> stk;
        TreeNode *newroot, *prev, *cur;
        while (root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	root = stk.top();
        	if(!getroot)
        	{
        		newroot = new TreeNode(root->val);
        		prev = newroot;
        		getroot = true;
        	}
        	else
        	{
        		cur = new TreeNode(root->val);
        		prev->right = cur;
        		prev = cur;
        	}
        	stk.pop();
        	root = root->right;
        }
        return newroot;
    }
};