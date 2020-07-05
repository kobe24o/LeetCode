class Solution {
	bool found = false;
	int allsum;
public:
    bool checkEqualTree(TreeNode* root) {
    	allsum = sum(root);
        if(allsum&1) return false;//奇数不可分
    	check(root);
    	return found;
    }
    int sum(TreeNode* root)
    {
    	if(!root) return 0;
    	int l = sum(root->left);
    	int r = sum(root->right);
    	return root->val += l+r;
    }
    bool check(TreeNode* root)
    {
    	if(!root) return false;
        if(found) return true;
    	if(root->left && allsum == 2*root->left->val)
    		return found = true;
    	if(root->right && allsum == 2*root->right->val)
    		return found = true;
    	return check(root->left) || check(root->right);
    }
};