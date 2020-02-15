class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        	return NULL;
        if(root->val < p->val && root->val < q->val)
        	return lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val)
        	return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};