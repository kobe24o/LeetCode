class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL)
        	return new TreeNode(val);
        if(root->val < val)
    	{
    		TreeNode *newNode = new TreeNode(val);
    		newNode->left = root;
    		return newNode;
    	}
    	else
    	{
    		root->right = insertIntoMaxTree(root->right, val);
    		return root;
    	}
    }
};