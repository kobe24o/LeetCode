class Solution {
	string ans;
public:
    string tree2str(TreeNode* t) {
        ans = treeToStr(t);
        return ans;
    }

    string treeToStr(TreeNode *root)
    {
    	if(root == NULL)
    		return "";
    	string sub(to_string(root->val));
    	sub.push_back('(');
    	if(root->left)
    	{
    		sub += treeToStr(root->left);
    		if(root->right)
    			sub += treeToStr(root->right);
    	}
    	else if(root->right)
    	{
    		sub += treeToStr(root->left);
    		sub += treeToStr(root->right);
    	}
    	sub.push_back(')');
    	return sub;
    }
};