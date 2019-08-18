class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        bool has = false;
        pathsum(root, 0, sum, has);
        return has;
    }
    void pathsum(TreeNode *root, int cursum, int &sum, bool &has)
    {
        if(!root || has)
            return;
        pathsum(root->left, cursum+root->val, sum, has);
        pathsum(root->right, cursum+root->val, sum, has);
        if(!root->left && !root->right && cursum+root->val == sum)
            has = true;
    }
};