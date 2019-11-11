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

		sub.push_back('(');//左边不管存在与否都要加括号
		sub += treeToStr(root->left);
		sub.push_back(')');

		if(root->right)//右边存在的时候才加括号，否则省略
		{
			sub.push_back('(');
			sub += treeToStr(root->right);
			sub.push_back(')');
		}	
    	return sub;
    }
};