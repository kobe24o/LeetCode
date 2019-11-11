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
    	if(!root->left && !root->right)
    		return sub;
    	
    	else if(root->left)
    	{
    		sub.push_back('(');
    		sub += treeToStr(root->left);
    		sub.push_back(')');
    		if(root->right)
    		{
    			sub.push_back('(');
    			sub += treeToStr(root->right);
    			sub.push_back(')');
    		}	
    	}
    	else
    	{
    		sub.push_back('(');
    		sub += treeToStr(root->right);
    		sub.push_back(')');
    	}    	
    	return sub;
    }
};