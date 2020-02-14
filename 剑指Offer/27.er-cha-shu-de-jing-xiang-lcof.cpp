class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
        	return root;
        mirrorTree(root->left);
        mirrorTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};