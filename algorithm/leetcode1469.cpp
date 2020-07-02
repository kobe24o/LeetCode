class Solution {
	vector<int> ans;
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        if(!root)
        	return {};
        if(!root->left && root->right)
        	ans.push_back(root->right->val);
        if(root->left && !root->right)
        	ans.push_back(root->left->val);
        getLonelyNodes(root->left);
        getLonelyNodes(root->right);
        return ans;
    }
};