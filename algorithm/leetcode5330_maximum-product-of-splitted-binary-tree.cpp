class Solution {
public:
    int maxProduct(TreeNode* root) {
        int sum = subsum(root);
        unsigned long long maxProduct = 1;
        dfs(root,sum,maxProduct);
        return int(maxProduct%1000000007);
    }

    int subsum(TreeNode* root)
    {
    	if(!root) return 0;
    	int l = subsum(root->left);
    	int r = subsum(root->right);
    	root->val += l+r;
    	return root->val;
    }

    void dfs(TreeNode* root, int& sum, unsigned long long& maxProduct)
    {
    	if(!root || (!root->left && !root->right)) return;
    	unsigned long long product;
    	if(root->left)
    	{
    		product = (unsigned long long)root->left->val * (sum-root->left->val);
    		if(product > maxProduct)
    			maxProduct = product;
    	}
    	if(root->right)
    	{
    		product = (unsigned long long)root->right->val * (sum-root->right->val);
    		if(product > maxProduct)
    			maxProduct = product;
    	}
    	dfs(root->left,sum,maxProduct);
    	dfs(root->right,sum,maxProduct);
    }
};