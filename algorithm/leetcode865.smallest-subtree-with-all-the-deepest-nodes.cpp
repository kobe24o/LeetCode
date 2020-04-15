class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode* root)
    {
        if(!root)
            return {0, NULL};
        pair<int, TreeNode*> l = dfs(root->left);
        pair<int, TreeNode*> r = dfs(root->right);
        if(l.first == r.first)
            return {l.first+1, root};
        else if(l.first > r.first)
            return {l.first+1, l.second};
        else
            return {r.first+1, r.second};
    }
};