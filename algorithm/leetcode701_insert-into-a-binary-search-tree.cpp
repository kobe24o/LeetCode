class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        	return new TreeNode(val);
        TreeNode *node = new TreeNode(val);
        TreeNode *child, *oringinalRoot = root;
        while(root)
        {
        	if(val > root->val)
    		{
	        	child = root->right;
	        	if(child == NULL)
	        		root->right = node;
	        	root = child;
	        }
	        else // val < root->val
	        {
	        	child = root->left;
	        	if(child == NULL)
	        		root->left = node;
	        	root = child;
	        }
	        return oringinalRoot;
        }
        return NULL;
    }
};