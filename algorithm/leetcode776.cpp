class Solution {
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {NULL, NULL};
        if(root->val <= V)
            return {root, root->right};
        ans.push_back(root);
        
    }
};