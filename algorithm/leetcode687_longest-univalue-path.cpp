class Solution {
	int maxlen = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
    	if(!root)
    		return 0;
        sameValue(root);
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return maxlen;
    }

    int sameValue(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	int leftLen = 0, rightLen = 0;
    	if(root->left && root->left->val == root->val)
    		leftLen = sameValue(root->left);
    	if(root->right && root->right->val == root->val)
    		rightLen = sameValue(root->right);
        maxlen = max(leftLen+rightLen, maxlen);
    	return 1+max(leftLen, rightLen);
    }
};

class Solution {
	int maxlen = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        sameValue(root);
        return maxlen;
    }

    int sameValue(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	int leftLen = sameValue(root->left);
    	int rightLen = sameValue(root->right);
    	int L = 0, R = 0;
    	if(root->left && root->left->val == root->val)
    		L = leftLen+1;
    	if(root->right && root->right->val == root->val)
    		R = rightLen+1;
        maxlen = max(L+R, maxlen);
    	return max(L, R);
    }
};