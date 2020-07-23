class Solution {
	int i = 0;
public:
    TreeNode* str2tree(string s) {
    	if(s == "") return NULL;
    	return buildTree(s);
    }
    TreeNode* buildTree(string &s)
    {
    	if(i == s.size() || s[i] == ')')
    		return NULL;
        int val = 0, neg = 1;
        if(s[i] == '-')
        {
            neg = -1;
            i++;
        }
        while(isdigit(s[i]))
            val = val*10 + neg*(s[i++]-'0');
    	TreeNode* root = new TreeNode(val);
    	if(i < s.size() && s[i] == '(' && !root->left)
    	{
    		i++;
    		root->left = buildTree(s);
    	}
    	if(i < s.size() && s[i] == '(' && !root->right)
    	{
    		i++;
    		root->right = buildTree(s);
    	}
        i++;
    	return root;
    }
};