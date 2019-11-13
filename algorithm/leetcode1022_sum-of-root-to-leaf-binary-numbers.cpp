class Solution {
	int sum = 0;
	int mod = 1e9+7;
public:
    int sumRootToLeaf(TreeNode* root) {
        sumRootToLeaf(root,0);
        return sum;
    }

    void sumRootToLeaf(TreeNode* root, int cursum)
    {
    	if(!root)
    		return;
    	cursum %= mod;//避免溢出
    	cursum = cursum*2+root->val;
    	if(!root->left && !root->right)
    	{
    		sum += cursum;
    		return;
    	}
    	else
    	{
	    	sumRootToLeaf(root->left, cursum);
	    	sumRootToLeaf(root->right, cursum);
	    }
    }
};