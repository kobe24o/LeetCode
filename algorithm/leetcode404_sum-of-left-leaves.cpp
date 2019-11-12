class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
        	return 0;
        int sum = 0;
        if(root->left && !root->left->left && !root->left->right)
        	sum += root->left->val;
        sum += sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        return sum;
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right))
        	return 0;
        int sum = 0;
        if(root->left && !root->left->left && !root->left->right)
        	sum += root->left->val;
        sum += sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        return sum;
    }
};