class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        	return new TreeNode(val);
        // TreeNode *node = new TreeNode(val);
        TreeNode *prev, *oringinalRoot = root;
        while(root)
        {
        	prev = root;
        	if(val > root->val)
	        	root = root->right;
	        else // val < root->val
	        	root = root->left;
        }
        if(val < prev->val)
        	prev->left = new TreeNode(val);
        else
        	prev->right = new TreeNode(val);
        return oringinalRoot;
    }
};