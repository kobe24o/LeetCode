class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	bool ans = true;
    	check(root, ans);
    	return ans;
    }

    int check(TreeNode* root, bool& bal)
    {
    	if(!root || !bal)
    		return 0;
    	int l = check(root->left);
    	int r = check(root->right);
    	if(abs(l-r)>1)
    		bal = false;
    	return max(l,r)+1;
    }
};