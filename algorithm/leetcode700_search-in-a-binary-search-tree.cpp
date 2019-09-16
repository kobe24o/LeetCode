class Solution {
	TreeNode *ans = NULL;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
        	return root;
        if(ans)
        	return ans;
        if(root->val == val)
    	{
    		ans = root;
    		return ans;
    	}
        else if(root->val < val)
        	searchBST(root->right, val);
        else
        	searchBST(root->left, val);
        return ans;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
        {
        	if(root->val == val)
        		return root;
        	else if(root->val < val)
        		root = root->right;
        	else
        		root = root->left;
        }
        return NULL;
    }
};