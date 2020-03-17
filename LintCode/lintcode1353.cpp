class Solution {
    int sum = 0;
public:
    int sumNumbers(TreeNode * root) {
        if(!root)
            return 0;
        dfs(root,0);
        return sum;
    }

    void dfs(TreeNode* root, int s)
    {
        if(!root)
            return;
        s = 10*s+root->val;
        dfs(root->left,s);
        dfs(root->right,s);
        if(!root->left && !root->right)
            sum += s;
    }
};