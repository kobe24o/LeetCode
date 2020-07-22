class Solution {
    vector<TreeNode*> ans;
    bool found = false;
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {NULL, NULL};
        if(root->val <= V)
            return {root, root->right};
        ans.push_back(root);
        split(root, NULL, 0, V);
        return ans;
    }
    void split(TreeNode* root, TreeNode* fa,int side, int V)
    {
        if(!root || found)
            return;
        if(root->val <= V && (!root->right || root->right->val > V))
        {
            found = true;
            if(side == 0)
                fa->left = root->right;
            else
                fa->right = root->right;
            if(ans[0] != root)
                ans.push_back(root);
            else
                ans.push_back(NULL);
            root->right = NULL;
            return;
        }
        split(root->left, root, 0, V);
        split(root->right, root, 1, V);
    }
};