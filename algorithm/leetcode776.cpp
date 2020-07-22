class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root)
            return {NULL, NULL};
        if(root->val > V)
        {
            auto l = splitBST(root->left, V);
            root->left = l[1];
            return {l[0], root};
        }
        else
        {
            auto r = splitBST(root->right, V);
            root->right = r[0];
            return {root, r[1]};
        }
    }
};