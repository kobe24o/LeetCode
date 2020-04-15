class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    	if(!root)
    		return NULL;
    	int hl = height(root->left);
    	int hr = height(root->right);
    	if(hl == hr)
    		return root;
    	else if(hl < hr)
    		return lcaDeepestLeaves(root->right);
		else
    		return lcaDeepestLeaves(root->left);
    }

    int height(TreeNode* root)
    {
    	if(!root)
    		return 0;
    	return 1+max(height(root->left),height(root->right));
    }
};