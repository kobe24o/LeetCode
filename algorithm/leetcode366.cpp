class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root)
        findLeaves(root->left);
        findLeaves(root->right);
    }
};