class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans;
        bool found = false;
        find(root, p, q, ans,found);
        return ans;
    }
    void find(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans, bool &found) 
    {
    	if(found)
    		return;
    	if(((root->val <= p->val)&&(root->val >= q->val))
    		|| ((root->val >= p->val)&&(root->val <= q->val)))
    	{
    		found = true;
    		ans = root;
    		return;
    	}
    	if((root->val < p->val)&&(root->val < q->val))
    		find(root->right, p, q, ans,found);
    	else if((root->val > p->val)&&(root->val > q->val))
    		find(root->left, p, q, ans,found);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val >= p->val && root->val <= q->val) 
        	return root;
        if(root->val > p->val && root->val > q->val) 
        	return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val) 
        	return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};