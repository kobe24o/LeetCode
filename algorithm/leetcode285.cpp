class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        stack<TreeNode*> stk;
        TreeNode *cur;
        bool found = false;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	cur = stk.top();
        	if(found)
        		return cur;
        	stk.pop();
        	root = cur->right;
        	if(cur == p)
        		found = true;
        }
        return NULL;
    }
};