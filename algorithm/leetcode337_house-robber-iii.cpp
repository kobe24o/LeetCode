class Solution {
	map<pair<TreeNode*,bool>,int> m;
public:
    int rob(TreeNode* root) {
        return max(rob(root,0),rob(root,1));
    }
    int rob(TreeNode* root, bool steal)
    {
    	if(root == NULL)
    		return 0;
    	if(m.find(make_pair(root,steal)) != m.end())
    		return m[make_pair(root,steal)];
    	if(steal)
		{
			int val = root->val + rob(root->left,0) + rob(root->right,0);
			m[make_pair(root,steal)] = val;
			return val;
		}
    	else//没有偷root
    	{
    		int val = max(rob(root->left,0),rob(root->left,1))+max(rob(root->right,0),rob(root->right,1));
    		m[make_pair(root,steal)] = val;
			return val;
    	}
    }
};